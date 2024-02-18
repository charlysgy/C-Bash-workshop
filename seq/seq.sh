#!/bin/sh

if [ ! $# -eq 3 ];
then
    echo "Usage: ./seq.sh FIRST INCREMENT LAST" 1>&2;
    exit 1;
fi

first="$1"
incr="$2"
end="$3"

[ $incr -eq 0 ] && exit 1;

if [ $first -eq $end ];
then
    echo "$first";
    exit 0;
else
    if [ $first -lt $end ] && [ $incr -gt 0 ];
    then
        while [ $first -lt $(($end + 1)) ];
        do
            echo $first;
            first=$(($first + $incr));
        done;
        exit 0;
    else
        if [ $first -gt $end ] && [ $incr -lt 0 ];
        then
            while [ $first -gt $(($end - 1)) ];
            do
                echo $first;
                first=$(($first + $incr));
            done;
            exit 0;
        fi
    fi
fi

exit 1

