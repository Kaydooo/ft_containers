#!/bin/bash

RED="\e[31m"
GREEN="\e[92m"
YELLOW="\e[33m"
BLUE="\e[34m"
CYAN="\e[36m"
MAGENTA="\e[35m"
WHITE_BK="\e[107m"
ENDCOLOR="\e[0m"

test_speed() {
    g++ -Werror -Wextra -Wall -std=c++98 $1/speed_test.cpp
    echo -e "${MAGENTA}$1 Speed_Test${ENDCOLOR}"

    echo -e "${MAGENTA}$1 100000 NUMBERS ${ENDCOLOR}"
    ft_speed=`{ time ./a.out ft 100000; } 2>&1 | grep real | awk '{print $2}'`
    std_speed=`{ time ./a.out std 100000; } 2>&1 | grep real | awk '{print $2}'`

    echo -e "${MAGENTA}$1 1000000 NUMBERS ${ENDCOLOR}"
    ft_speed=`{ time ./a.out ft 1000000; } 2>&1 | grep real | awk '{print $2}'`
    std_speed=`{ time ./a.out std 1000000; } 2>&1 | grep real | awk '{print $2}'`

    echo -e "${MAGENTA}$1 10000000 NUMBERS ${ENDCOLOR}"
    ft_speed=`{ time ./a.out ft 10000000; } 2>&1 | grep real | awk '{print $2}'`
    std_speed=`{ time ./a.out std 10000000; } 2>&1 | grep real | awk '{print $2}'`

    echo -e "FT Speed = ${GREEN} $ft_speed ${ENDCOLOR}"
    echo -e "STD Speed = ${GREEN} $std_speed ${ENDCOLOR}"
    rm a.out
}

# test_functions() {
#     g++ -Werror -Wextra -Wall -std=c++98 $1/test1.cpp
#     echo -e "${MAGENTA}$1 Speed_Test${ENDCOLOR}"
#     if [ $# -eq 1 ]
#     then
#         ft_speed=`{ time ./a.out ft ; } 2>&1 | grep real | awk '{print $2}'`
#         std_speed=`{ time ./a.out std ; } 2>&1 | grep real | awk '{print $2}'`
#     else
#         ft_speed=`{ time ./a.out ft ; } 2>&1 | grep real | awk '{print $2}'`
#         std_speed=`{ time ./a.out std ; } 2>&1 | grep real | awk '{print $2}'`
#     fi
#     echo -e "FT Speed = ${GREEN} $ft_speed ${ENDCOLOR}"
#     echo -e "STD Speed = ${GREEN} $std_speed ${ENDCOLOR}"
# }


if [ $# -ge 1 ]
then
    test_speed $1
    exit
fi

test_speed vector
test_speed map 
test_speed set





