#!/bin/bash

numTests=10
#numCountMax=20
numCount=10
declare -a numArr
sum=''
avg=''
minNum=''
maxNum=''
score=0
	# Generate numbers
	echo Test $test for minimum value..................
	#numCount=$(($RANDOM%$numCountMax+1))
	for (( idx=0; idx<$numCount; idx=idx+1 )); do
		numArr[$idx]=$(($RANDOM%1000))
	done
	echo List of numbers: ${numArr[@]}

	
	minNum=${numArr[0]}
	for (( idx=0; idx<$numCount; idx=idx+1 )); do
		if [ "${numArr[$idx]}" -lt "$minNum" ]; then
			minNum=${numArr[$idx]}
		fi
	done
	
	
	output=$(echo $(./a.out ${numArr[@]}) | awk '{print $2;}')
	expected_output="$minNum"
	
	if [ $? -eq 0 ]; then
		echo "Program executed successfully"
	else
		echo "Program failed to execute"
		exit 1
	fi
	
	if [ "$output" == "$expected_output" ]; then
		echo "Passed test for average value: expected output: '$expected_output', your output: '$output'"
		score=$(($score + 1))
	else
		echo "Failed test for average value: expected output: '$expected_output', your output: '$output'"
		exit 1
	fi
	


echo "Test completed"
# echo "Final score: $score"
