#!/bin/bash

# Make sure exactly two arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Error: Two arguments required - <filesdir> <searchstr>"
    exit 1
fi

# Assign arguments to variables
filesdir=$1
searchstr=$2

# Check filesdir
if [ ! -d "$filesdir" ]; then
    echo "Error: $filesdir is not a valid directory"
    exit 1
fi

# Count matching files
num_files=$(find "$filesdir" -type f | wc -l)

# Count matching lines
num_matching_lines=$(grep -r "$searchstr" "$filesdir" 2>/dev/null | wc -l)

# Echo the result
echo "The number of files are $num_files and the number of matching lines are $num_matching_lines"