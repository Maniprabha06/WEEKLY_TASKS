#!/bin/bash

for file in *;do
	if [ -f "$file" ]; then
		echo "$file is a file"
	elif [ -d "$file" ]; then
		echo "$file is a directory"
	else
		echo "$file is something else"
	fi
done
