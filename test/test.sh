#!/bin/bash

DFLAG="-g"
COMP="gcc"
LFLAG="-lft"
DIRLIB="-L../../ft_printf2/libft/"
CFLAG="-Wall -Wextra"
INCLUDES="-I.. -I../../ft_printf2/libft/includes"
SRCS="../ft_printf_printers2.c ../ft_printf.c"

function build_test
{
	av_tests="c s d u i p xu xl pe"
	for test in $av_tests
	do
	if [ "$test" = "$1" ]
	then
		TFLAG=-DD42_TEST_${test^^}
		TNAME=${test,,}.fake
		clear
		echo "I'll first list the return problem cases : "
		read -n 1
		$COMP $DFLAG $CFLAG $INCLUDES $TFLAG $DIRLIB test.fake.c $SRCS -o $TNAME $LFLAG
		./$TNAME > $TNAME.log
		TNAME=${test,,}.orig
		$COMP $DFLAG $CFLAG $INCLUDES $TFLAG $DIRLIB test.orig.c $SRCS -o $TNAME $LFLAG
		./$TNAME > $TNAME.log
		echo "Now the diffs for printed out strings :"
		read -n 1
		diff -U 1 ${test,,}.fake.log ${test,,}.orig.log > ${test,,}.diff
		less ${test,,}.diff
		return 0
	fi
	done
	echo "Test not found"
	echo "Available tests are : $av_tests"
}

if [ "$#" = 2 ]
then
	tests="c"
	echo "1$tests"
else
	tests=$1
	echo "2$tests"
fi
build_test $tests
