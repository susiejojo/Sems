#!/bin/bash
declare -i flag
flag=0
# while [ $flag -eq 0 ];do
	d=$(date +"%T")
	filename="$1"
	while read -r line; do
		name="$line"
		echo "Reads: $name"
	done < "$filename"

# flag=1
fi
done