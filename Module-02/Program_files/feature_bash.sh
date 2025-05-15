#!/bin/bash

count_lines() {
    if [ -z "$1" ]; then
        echo "Usage: $0 <filename>"
        return 1
    fi
	
	if [ ! -f "$1" ]; then
		echo "Error: File '$1' not found"
		return 1
	fi
	lines=$(wc -l < "$1")
	echo "The file '$1' has $lines lines."
}
count_lines "$1"
