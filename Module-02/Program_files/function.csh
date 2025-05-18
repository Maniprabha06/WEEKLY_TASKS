#!/bin/csh

if ($#argv == 0) then
    echo "Usage: $0 <number>"
    exit 1
endif


set num = $1


if ("$num" !~ [0-9]*) then
    echo "Invalid input: not a number"
    exit 1
endif


@ mod = $num % 2


if ($mod == 0) then
    set parity = "even"
else
    set parity = "odd"
endif

switch ($parity) 
	case "even":
		echo "Even number"
		breaksw
	case "odd":
		echo "Odd number"
		breaksw
	default:
		echo "Unknown parity"
		breaksw
endsw
