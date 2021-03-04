#!/bin/bash
if [[ $# -ne 2 ]]
then
echo "Need exactly 2 arguments"
else
	for file in $(find -iname "*$1" | cut -c 3-)
	do
		$(mv $file $2$file)
	done
	echo "Done!"
fi
