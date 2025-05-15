#!/bin/csh

set filename = "$1"

if (! -f "$filename") then
	echo "error : file '$filename' not found"
	exit 1
endif

set lines = `wc -l < "$filename"`
echo "this '$filename' has $lines of lines"
