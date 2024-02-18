#!/bin/sh

[ "$#" -ne 2 ] && exit 1;
[ "$2" = "nan" ] && exit 1;
[ ! "$2" -gt 0 ] && exit 1;
[ ! -f "$1" ] && exit 1;

input="$1"

i=1
while IFS= read -r line || [ -n "$line" ]
do
    if [ $i -ne "$2" ]
    then
        i=$((i+1));
    else
        first=$(echo -n "$line" | cut -d ';' -f 2);
        [ "$first" = "" ] && exit 1;
        second=$(echo -n "$line" | cut -d ';' -f 3);
        [ "$second" = "" ] && exit 1;
        echo "$first is $second";
        exit 0;
    fi
done < "$input"
exit 1;
