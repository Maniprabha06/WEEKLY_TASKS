#!/bin/csh

echo "Getting user input ussing Csh script"
echo -n "Enter your name :"
set name = $<

if ("$name" == "Prabha") then
	echo "Welcomeback Prabhaaa"
else if ("$name" == "Mano") then
	echo "Welcomeback Manooo"
else
	echo "WelcomeBack $name"
endif

