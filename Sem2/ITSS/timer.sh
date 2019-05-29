#!/bin/bash

declare -i flag
flag=0
while [ $flag -eq 0 ];do
	d=$(date +"%T")
#echo $d
if [ $d == "19:30:00" ]; then
notify-send 'Time to have food!!'
fi
if [ $d == "19:13:00" ]; then
	notify-send 'This works!'
fi
if [ $d == "00:00:00" ]; then
notify-send 'Leave workspace'
flag=1
fi
done