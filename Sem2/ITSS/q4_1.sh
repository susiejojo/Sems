#!/bin/bash
declare -i flag
declare -i count
flag=0
command=$1
time=$2
message=$3
freq=$4
count=1
while [ $flag -ne 1 ];do
if [[ "$command" = "Create" ]];then
	a=($(wc reminders.txt))
	count=${a[0]}
	count=`expr $count + 1`
	echo $count $2 $3 $4 >> reminders.txt
	echo "Reminder set with id = "$count
	flag=1
fi
if [[ "$command" = "Delete" ]];then
	echo "Deleting reminder with id = "$2
	id=$2
	awk -v d1="$id" '( $1!=d1 )' reminders.txt > temp.txt && mv temp.txt reminders.txt  
	flag=1
fi
if [[ "$command" = "List" ]];then
	echo "Here's the list you've set so far:"
	sort -k2 -n -k1 -n reminders.txt
	flag=1
fi
if [[ "$command" = "Edit" ]];then
	if [ $# -eq 3 ];then
		id=$2
		time=$3
		awk -v d1="$id" -v dtime="$time" '{ if ($1==d1) $2=dtime; print $0 }' reminders.txt > temp.txt && mv temp.txt reminders.txt  
		flag=1
	fi
	if [ $# -eq 4 ];then
		id=$2
		time=$3
		message=$4
		awk -v d1="$id" -v dtime="$time" -v dm="$message" '{ if ($1==d1) { $2=dtime; $3=dm } print $0 }' reminders.txt > temp.txt && mv temp.txt reminders.txt  
		flag=1
	fi
	if [ $# -eq 5 ];then
		id=$2
		time=$3
		message=$4
		freq=$5
		awk -v d1="$id" -v dtime="$time" -v dm="$message" -v df="$freq" '{ if ($1==d1) { $2=dtime; $3=dm; $4=df } print $0 }' reminders.txt > temp.txt && mv temp.txt reminders.txt  
		flag=1
	fi
fi


done