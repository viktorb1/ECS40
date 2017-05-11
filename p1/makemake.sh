#! /bin/bash

case $# in
	0)	echo 'Executable name required.'
			echo 'usage: makemake.sh executable_name'
			exit 1 ;;
esac

exename="$1"
shift; flags="$*"

rm -f Makefile
touch Makefile

filenames=( *.cpp )
filenames=("${filenames[@]%.cpp}")

{
# COMPILE EXECUTABLE SECTION
echo -n "$exename : "

for file in "${filenames[@]}"; do
	echo -n "$file.o "
done

echo " "

echo -en "\tg++ -ansi -Wall -g -o $exename $flags "

for file in "${filenames[@]}"; do
	echo -n "$file.o "
done

echo " "
echo

# LOOP FOR COMPILING ALL OBJECT FILES
for file in "${filenames[@]}"; do

	dependencies=("$(grep '#include "' "$file.cpp" | sed 's/#include //' | sed 's/"//g' | sed 's/.*://' | tr '\n' ' ')")

	echo -n "$file.o : $file.cpp "

	for dependancy in "${dependencies[@]}"; do
		echo -n "$dependancy"
	done

	echo -e "\n\tg++ -ansi -Wall -g -c $flags $file.cpp\n"
done

# CLEAN SECTION
echo -en "clean : \n\trm -f $exename "

for file in "${filenames[@]}"; do
	echo -n "$file.o "
done

echo " "

} >> Makefile