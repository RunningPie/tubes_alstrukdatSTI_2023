#!/bin/bash

echo "run!"

# Get the list of all C source code files in the different directory
C_SOURCE_FILES=$(find ../ -name "*.c")

echo $C_SOURCE_FILES

# Concat all source codes into one string
# ALL_SOURCE = $""
# for file in $C_SOURCE_FILES; do
#     $ALL_SOURCE = $ALL_SOURCE + " " + $file
# done

# Compile all sources
gcc -o all.exe $C_SOURCE_FILES

mv all.exe /bin

# Run exe
./bin/all.exe

# Run the executable file
# ./bin/$(basename $C_SOURCE_FILES .c)

# Compile each C source code file
# for file in $C_SOURCE_FILES; do
#     gcc $file -o ../bin/$(basename $file .c)
#     echo $file
# done
