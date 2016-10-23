#!/bin/sh
for x in $*
do
echo "cat>$x<<here
abc\
def\
ghi
here"
done>>recreate
