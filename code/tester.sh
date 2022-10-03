#!/bin/bash

for i in `seq 1 25`;
do
	a=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`
	b=`./push_swap $a | wc -l`
	echo -e "$a$b"
done

for i in `seq 1 1`;
do
	a=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
	b=`./push_swap $a | wc -l`
	echo -e "$a$b"
done
