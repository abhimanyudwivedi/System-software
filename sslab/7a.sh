#!/bin/sh
echo "the input is: $*"
for x in "$@"
do
y=$x" "$y
done
echo "reverse :$y"
