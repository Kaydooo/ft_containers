#!/bin/bash

RED="\e[31m"
GREEN="\e[92m"
YELLOW="\e[33m"
BLUE="\e[34m"
CYAN="\e[36m"
MAGENTA="\e[35m"
WHITE_BK="\e[107m"
ENDCOLOR="\e[0m"
numbers=100000

echo > diff.txt
test_speed() {
    # $1 Container 
    # $2 Numbers
    echo -e "${MAGENTA}$1 speed_test${ENDCOLOR}"
    echo -e "${CYAN}$2 NUMBERS ${ENDCOLOR}"
    g++ -Werror -Wextra -Wall -std=c++98 $1/speed_test.cpp -D=FT2 > /dev/null
    ft_speed=`{ time ./a.out $2; } 2>&1 | grep real | awk '{print $2}'`
    g++ -Werror -Wextra -Wall -std=c++98 $1/speed_test.cpp -D=STD > /dev/null
    std_speed=`{ time ./a.out $2; } 2>&1 | grep real | awk '{print $2}'`

    echo -e "FT Speed = ${GREEN} $ft_speed ${ENDCOLOR}"
    echo -e "STD Speed = ${GREEN} $std_speed ${ENDCOLOR}"
    rm a.out
}

test() {
    # $1 Container
    # $2 test_type
    g++ -Werror -Wextra -Wall -std=c++98 $1/$2.cpp  -D=FT  2> /dev/null
    ./a.out > ft_output_test1
    g++ -Werror -Wextra -Wall -std=c++98 $1/$2.cpp  -D=STD 2> /dev/null
    ./a.out > std_output_test1

    diff=`diff ft_output_test1 std_output_test1`
    if [ -z "$diff" ]
    then
        echo -e "${MAGENTA}$1 $2 test ${ENDCOLOR}${GREEN}PASS${ENDCOLOR}"
    else
        echo -e -n "${MAGENTA}$1 $2 test ${ENDCOLOR}${RED}FAIL${ENDCOLOR}"
        echo " check diff at diff.txt: "
        echo "------------------$1 $2-------------------" >> diff.txt
        echo " $diff " >> diff.txt
    fi
    rm -r a.out ft_output_test1 std_output_test1
}


if [ $# -ge 1 ]
then
    test_speed $1 $numbers
    exit
fi
echo "-------------------------------------------------------"
test_speed vector $numbers
echo "-------------------------------------------------------"
test_speed map $numbers
echo "-------------------------------------------------------"
test_speed set $numbers
echo "-------------------------------------------------------"
test vector constructor
echo "-------------------------------------------------------"
test vector iterator
echo "-------------------------------------------------------"
test vector capacity
echo "-------------------------------------------------------"
test vector element_access
echo "-------------------------------------------------------"
test vector modifiers
echo "-------------------------------------------------------"
test vector re_op
echo "-------------------------------------------------------"





