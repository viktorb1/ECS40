#!/bin/bash

filenames=(*.c)

for file in "${filenames[@]}"; do
   sed -i '/^\/\*/, /^\*\//d' "$file"
done