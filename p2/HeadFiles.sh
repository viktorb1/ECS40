#! /bin/bash

case $# in
	0) filenames=(*.txt) ;;
	*) filenames=("$@") ;;
esac

for file in "${filenames[@]}"; do
	echo "Displaying first 3 lines of $file:"
	head -n 3 "$file"
	echo -ne "\nDelete file $file? (y/n) "
	read -r yn

	if [ "$yn" = 'y' ]; then
		rm -f "$file"
	fi

done