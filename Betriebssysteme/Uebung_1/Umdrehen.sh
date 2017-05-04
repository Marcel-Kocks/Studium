#!/bin/bash


#echo ${#1}
for((i=${#1}; i>=0;i--));
do
	echo -n ${1:$i:1}
done
echo
