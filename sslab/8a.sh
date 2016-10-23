#!/bin/sh
echo "arguments are: $*"
pr1=`ls -l $1|cut -f1 -d " "`
pr2=`ls -l $2|cut -f1 -d " "`
if [ "$pr1" = "$pr2" ] 
then
echo "permissions are equal:$pr1"
else
echo "permissions are different"
echo "permission 1 : $pr1"
echo "permission 2 : $pr2"
fi
