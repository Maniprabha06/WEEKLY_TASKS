#!/bin/csh

foreach file (*)
	if (-f $file) then
		echo "$file is a file"
	else if (-d $file) then
		echo "$file is a directory"
	else
		echo "$file is something else"
	endif
end
