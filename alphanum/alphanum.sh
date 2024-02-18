#!/bin/sh

while read line
do
    if echo $line | egrep -q "^[a-zA-Z]+$";
    then
        echo "it is a word";
    else
        if echo $line | egrep -q "^[0-9]{2,}$";
        then
            echo "it is a number";
        else
            if echo $line | egrep -q "^[0-9]$";
            then
                echo "it is a digit";
            else
                if echo $line | egrep -q "^[a-zA-Z0-9]+$";
                then
                    echo "it is an alphanum";
                else
                    if echo $line | egrep -q "^[ \n\t\v]*$";
                    then
                        echo "it is empty"
                    else
                        echo "it is too complicated";
                        exit 0;
                    fi
                fi
            fi
        fi
    fi
done < "${1:-/dev/stdin}"
