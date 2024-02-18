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
        res=$(echo -n "$line" | sed -E 's/^([a-zA-Z]| |_|-)+;//' | sed -E 's/;/ is /' | sed -E 's/;.*//');
        echo "$res";
        [ $(echo "$res" | wc -w) -lt 3 ] && exit 1;
        exit 0;
    fi
done < "$input"
exit 1;
