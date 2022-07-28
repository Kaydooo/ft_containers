#!/bin/bash

RED="\e[31m"
GREEN="\e[92m"
YELLOW="\e[33m"
BLUE="\e[34m"
CYAN="\e[36m"
MAGENTA="\e[35m"
WHITE_BK="\e[107m"
ENDCOLOR="\e[0m"


if [ $# -lt 1 ]
then
    echo -e "$REDPlease Choose container along with test type .. for example  $GREEN ./mtester vector speed $ENDCOLOR"
    exit
else
    path_to_test_file=./$1
fi


g++ -Werror -Wextra -Wall -std=c++98 $path_to_test_file/speed_test.cpp
echo -e "${MAGENTA}$1 Speed_Test${ENDCOLOR}"

if [ $# -eq 1 ]
then
    ft_speed=`{ time ./a.out ft $1 ; } 2>&1 | grep real | awk '{print $2}'`
    std_speed=`{ time ./a.out std $1 ; } 2>&1 | grep real | awk '{print $2}'`
else
    ft_speed=`{ time ./a.out ft ; } 2>&1 | grep real | awk '{print $2}'`
    std_speed=`{ time ./a.out std ; } 2>&1 | grep real | awk '{print $2}'`
fi
echo -e "FT Speed = ${GREEN} $ft_speed ${ENDCOLOR}"
echo -e "STD Speed = ${GREEN} $std_speed ${ENDCOLOR}"

