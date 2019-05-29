#!/bin/bash
declare -i var1
declare -i var2
var1=1
var2=1
echo $var1
echo $var2
while [ $var1 -le "100"  ];do
	declare -i temp
	temp=var1
	var1=var1+var2
	var2=temp
	temp=var1%2
	if [ $temp -eq 1 ];then
		echo $var1
	fi
done


