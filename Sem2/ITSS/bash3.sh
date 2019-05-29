#!/bin/bash
read -p "What's ur age?" var
if [ $var -ge 18 ]
then
	echo "You r old enough to drink"
else
	echo "Oops too young!!"
fi
