#! /bin/bash
filenames=(*.c)

for file in "${filenames[@]}"; do
	if grep -Eq "^(fprintf\()|^(printf\()|[ \t]+(printf\()|[ \t]+(fprintf\()" "$file"; then
		if ! grep -q '#include <stdio.h>' "$file"; then
			sed -i '1s/^/#include <stdio.h>\n/' "$file"
		fi
	fi
done