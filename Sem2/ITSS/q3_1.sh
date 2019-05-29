#!/bin/bash
declare -i var
declare -i cycle
cycle=$1
var=0 
if [ $# -eq 1 ]; then 
while [ $var -ne $cycle ]; do
	declare -i temp
	temp=var%4
	if [ $temp -eq 0 -a $var -gt 0 ];then
	echo Long break...byeee!
	sleep 2
else
echo This is cycle $((var + 1))
notify-send 'This is cycle' $((var + 1))
echo Time to work!
notify-send 'Time to work!!'
sleep 2
echo Time to go to sleep!!zzz
notify-send 'Time to go to sleep!!zzz'
sleep 3

fi
((var++))
done
echo End of cycle. Tata!
notify-send 'End of cycle. Tata!'
else 
echo Enter right no. of arguments please!!!
fi
