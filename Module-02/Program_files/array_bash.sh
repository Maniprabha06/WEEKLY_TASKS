#!/bin/bash

places=("India" "London" "Paris" "Europe" "Africa" "Russia")

echo "Printing all places ${places[@]}"

echo "Print first place ${places[0]}"
echo "print second place ${places[1]}"

echo "Number of places ${#places[@]}"

for place in "${places[@]}"; do
	echo "place : $place"
done
