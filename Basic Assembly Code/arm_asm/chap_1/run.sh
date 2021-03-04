#!/bin/bash
#This is a comment
if [ -a main.s ] #if statement is TRUE when the file is present
	then
		echo "main.s present";
		echo "compilation start";
			as main.s -o a.out
			ld a.out -o a
		echo "compilation end";
else
	echo "main.s not present";
	echo "creating file \"main.s\"...";
	touch main.s
	if [ -a main.s ] 
	then
		echo "created file \"main.s\"";
	fi
	echo "Entering basic file content";
	echo .global _start>main.s	#'>' This will enter only one line
	echo _start:>>main.s		#'>>' This will append the given line
	echo bkpt>>main.s
	echo "basic file content Added";

	
fi
