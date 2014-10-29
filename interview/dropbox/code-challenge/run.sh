#!/bin/bash

export OUTPUT_PATH=output.txt
for i in `seq 0 8`;
do
    cat ./test_cases_word-pattern/input00$i.txt | ./word-pattern
    output=`cat output`
    golden=`cat ./test_cases_word-pattern/output00$i.txt`
    echo "Case $i: $golden vs $output"
done

rm $OUTPUT_PATH
