#!/bin/bash
if [ $# -eq "2" ]; then
sum=$(($1+$2))
echo $sum
else
	echo Error
fi

