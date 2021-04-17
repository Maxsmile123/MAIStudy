#!/bin/bash

if [[ $# -ne 2 ]]
then
	echo "Need exactly 2 arguments"
else
	for file in $(find -iname "*$1" -type f)
	do
		file2=$(echo $file | rev | cut -d '/' -f1 | rev)
		lenOfFile=$(echo $file2 | wc -c)
		path=$(echo $file | rev | cut -c $lenOfFile- | rev)
		$(mv $file $path$2$file2)
	done
	echo "Done"
fi
