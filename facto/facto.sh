#!/bin/sh

[ $# -lt 1 ] && exit 1;
[ $# -gt 1 ] && exit 1;

for arg;
do  res=1;
    while [ $arg -gt 0 ];
    do res=$(($res * $arg));
        arg=$(($arg - 1));
    done;
    echo $res;
done;
