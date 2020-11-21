#!/bin/bash

if [ $# -ne 1 ]; then
    echo "number of argments should be 1"
    return 1
fi

dir_name=${1##*/}
echo $dir_name

if [ -e $dir_name ]; then
    echo "$dir_name has already exist"
    return 1
fi

mkdir -p $dir_name
cp $(dirname $0)/template.cpp $dir_name/main.cpp
cd $dir_name
oj d $1