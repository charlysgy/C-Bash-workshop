#!/bin/sh

if [ $# -eq 1 ]
then
    echo $(($1));
    exit 0;
fi
while read line
do
    echo $(($line))
done < "${1:-/dev/stdin}"
