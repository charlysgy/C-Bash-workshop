#!/bin/sh

FILENAME=default
NUMBER=1
EXTENSION=txt

while [ $# -gt 0 ]
do  case "$1" in
    "-f"|"--filename")
        shift;
        FILENAME="$1";
        shift;
        ;;

    "-n"|"--number")
        shift;
        NUMBER="$1";
        shift;
        ;;

    "-e"|"--extension")
        shift;
        EXTENSION="$1";
        shift;
        ;;

    "$FILENAME"|"$NUMBER"|"$EXTENSION")
        continue;
        ;;
    *)
        exit 1;
        ;;
    esac
done
for i in $(seq $NUMBER)
do touch -- "$FILENAME-$i.$EXTENSION"
done
