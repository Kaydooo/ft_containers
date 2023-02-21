#!/bin/bash

RED="\e[31m"
GREEN="\e[92m"
YELLOW="\e[33m"
BLUE="\e[34m"
DBLUE="\e[94m"
BOLD="\e[1m"
CYAN="\e[36m"
MAGENTA="\e[35m"
WHITE_BK="\e[107m"
ENDCOLOR="\x1b[0m"
numbers=(10000 100000 1000000 10000000)
names=("vector" "stack" "map" "set")

# Change this to your containers header files dir
headers_dir="../inc"
echo > errors.diff

print_header () {
printf "${BOLD}${DBLUE}\
◤━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━◥
			     FT_CONTAINERS TESTER
◣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━◢
${ENDCOLOR}"
}

print_title()
{
    echo -e "\n${BOLD}${YELLOW}$1${ENDCOLOR}"
    echo "-----------------------------------------------------------------------"
}

test_speed() {
    # $1 Container 
    # $2 Numbers
    g++ -Werror -Wextra -Wall -I$headers_dir  -std=c++98 $1/speed/speed_test.cpp -D=FT 2> temp.txt
    compile_res=`cat temp.txt`
    if [ -z "$compile_res" ]
    then
        compiled=✅
        ft_speed=`{ time ./a.out $2; } 2>&1 | grep real | awk '{print $2}'`
        g++ -Werror -Wextra -Wall -std=c++98 $1/speed/speed_test.cpp -D=STD -DCPATH=PATH > /dev/null
        std_speed=`{ time ./a.out $2; } 2>&1 | grep real | awk '{print $2}'`
        printf "%-20s${GREEN}%-20s%-20s%-20s\n${ENDCOLOR}" $2 $compiled $ft_speed $std_speed
        rm a.out
    else
    compiled=❌
    ft_speed="0s"
    std_speed="0s"
    printf "%-20s${RED}%-20s%-20s%-20s\n${ENDCOLOR}" $2 $compiled $ft_speed $std_speed
    fi
    rm temp.txt
}

test() {
    # $1 test_type
    g++ -Werror -Wextra -Wall -I$headers_dir -std=c++98 $1 -D=FT  2> temp.txt
    compile_res=`cat temp.txt`

    if [ -z "$compile_res" ]
    then
        compiled="✅"
        ./a.out > ft_output_test1
        g++ -Werror -Wextra -Wall -std=c++98 $1 -D=STD 2> /dev/null
        ./a.out > std_output_test1
        diff=`diff ft_output_test1 std_output_test1`
        rm -r a.out ft_output_test1 std_output_test1
        if [ -z "$diff" ]
        then
            result="Pass"
            printf "%-30s%-31s${GREEN}%-30s\n" $1 $compiled $result
        else
            result="Fail"
            echo "------------------$1-------------------" >> errors.diff
            echo " $diff " >> errors.diff
            printf "%-30s%-31s${RED}%-30s\n" $1 $compiled $result
        fi
    else
        compiled=❌
        result="Fail"
        printf "%-30s%-31s${RED}%-30s\n" $1 $compiled $result
    fi
    echo -e -n ${ENDCOLOR}
    rm temp.txt
}


run_tests()
{
    print_title "SpeedTest"
    for name in ${names[@]}; do
        printf "${BOLD}${MAGENTA}%35s${ENDCOLOR}\n" ${name}
        printf "${BOLD}%-20s%-20s%-20s%-20s\n${ENDCOLOR}" "Numbers" "Compiled" "FT" "STD"
        for num in ${numbers[@]}; do
            test_speed $name $num
        done
        echo "-----------------------------------------------------------------------"
    done

    print_title "FunctionTest"
    for name in ${names[@]}; do
        printf "${BOLD}${MAGENTA}%35s${ENDCOLOR}\n" ${name}
        printf "${BOLD}%-30s%-30s%-30s\n${ENDCOLOR}" "Test" "Compiled" "Result"
            for f in $name/*.cpp; do
                test $f
            done
        echo "-----------------------------------------------------------------------"
    done
}

if [ $# -ge 1 ]
then
    names=($@)
fi

print_header
run_tests