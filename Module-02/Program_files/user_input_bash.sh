#!/bin/bash

echo "Getting user input using Bash"
read -p "Enter the name : " name

if [ "$name" = "Prabha" ]; then
	echo "Welcome Prabha"
elif [ "$name" = "Priya" ]; then
	echo "Welcome priya"
else
	echo "Welcome $name"
fi
