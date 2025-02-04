#!/bin/bash

# Check if at least one argument (source file) is provided
if [ $# -eq 0 ] ; then
    echo 'Please, provide a file to compile'
    exit 1
fi

# Get the base name of the first argument (remove extension)
output=$(basename $1 .cpp) # Assuming the file extension is '.cpp', adjust if needed

# If two arguments are provided, set the output file to the second argument
if [ $# -eq 2 ] ; then
    output=$2
fi

# Compile the source code using g++ with the correct output file
g++ $1 googletest/build/lib/libgtest.a -lpthread -I googletest/googletest/include/ -o $output

