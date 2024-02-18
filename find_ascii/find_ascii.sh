#!/bin/sh

for f in "$1"/*
do
    file "$f" | grep 'ASCII';
done

