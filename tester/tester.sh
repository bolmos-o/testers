#!/bin/bash

tests="100"
a="0"
elem="3"
echo -e "\t\tTESTS $elem ELEMENTS\n"
while [ $a -lt $tests ]
do
    if [ $a == $[$tests/4] ]
        then
            elem="5"
            echo -e "\n\t\tTESTS $elem ELEMENTS\n"
    fi
    if [ $a == $[2*$tests/4] ]
        then
            elem="100"
            echo -e "\n\t\tTESTS $elem ELEMENTS\n"
    fi
    if [ $a == $[3*$tests/4] ]
        then
            elem="500"
            echo -e "\n\t\tTESTS $elem ELEMENTS\n"
    fi
    echo "test $[$a+1] ($elem elements)"
    ARG=`python3 numgen.py $elem`;
    # echo $ARG
    #valgrind ../push_swap $ARG > log
    echo -n -e "\toperations:\t\t"; echo -n `../push_swap $ARG | wc -l` 
    echo -n -e "\tresult:\t"; ../push_swap $ARG | ../checker $ARG
    a=$[$a+1]
done
