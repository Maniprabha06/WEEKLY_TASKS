#!/bin/bash

check_number() {
	num=$1

	if ! [[ "$num" =~ ^[0-9]+$ ]]; then
		echo "Invalid input: Not an number"
		return 1
	fi

	if [ $((num%2)) -eq 0 ]; then
		parity="even"
	else
		parity="odd"
	fi

	case "$parity" in
		even)
			echo "$num is even"
			;;
		odd)
			echo "$num is odd"
			;;
		*)
			echo "Unknown result"
			;;
	esac
}
check_number "$1"
