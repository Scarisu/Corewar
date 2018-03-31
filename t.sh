#!/bin/sh
while [ $# -ne 0 ]
do
	./resources/asm $1
	shift
done
