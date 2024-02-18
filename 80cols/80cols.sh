#!/bin/sh

[ ! $# -eq 1 ] && exit 1;
[ ! -f $1 ] && exit 1;
while IFS= read -r line
do
    COUNT=$( echo "$line" | wc -m );
    if [ $COUNT -gt 80 ]; then
        printf "%s\n" "$line";
    fi;
done < "$1"

exit 0
