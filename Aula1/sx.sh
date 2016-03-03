#!/bin/bash

#echo -n "Enter name of the file: "
#read file


if [ -f $1 ] ; then
 echo -n "Removing file: $1 "
 printf "\n"
 rm -f $1
fi

gcc "$1.c" -o $1 -Wall



if [ $? -eq 0 ]; then ./$1
else
 echo -n "COMPILATION ERROR"
fi


