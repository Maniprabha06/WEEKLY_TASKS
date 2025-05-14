#!/bin/csh

set places = (India Russia Africa Switzerland London Europe)

echo "Print all places $places"
echo "Print first place $places[1]"
echo "print second place $places[2]"

foreach place ($places)
	echo "place : $place"
end 
