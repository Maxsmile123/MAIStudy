#!/bin/bash

ord() {
  LC_CTYPE=C printf '%d' "'$1"
}

function comparator() { # return 1 if first greater then second. recive two string
    minLen=0
    if [ ${#1} -ge ${#2} ]
    then
        len=${#2}
        minLen=0
    else 
        len=${#1}
        minLen=1
    fi
    cnt=0
    flag=0 # if true then first greater then two because of register
    for ((k = 0; k < $len; k++))
    do
        char1=${1:$k:1}
        char2=${2:$k:1}
        char1Int=$(ord $char1)
        char2Int=$(ord $char2)
        if [ $char1Int -eq $(($char2Int - 32)) ]
        then
            if [ $flag -ne 1 ]
            then
                flag=2
            fi
        elif [ $(($char1Int - 32)) -eq $char2Int ]
        then
            flag=1
        fi
        char1=${char1^^}
        char2=${char2^^}
        if [ $char1 \< $char2 ]
        then
            return 1
        elif [ $char1 = $char2 ]
        then
            cnt=$(($cnt + 1))
            
            continue
        else
            return 0
        fi
    done
    if [ $flag -eq 1 ]
    then
        return 1
    elif [ $flag -eq 2 ]
    then
        return 0
    elif [ $cnt -eq $len ]
    then
        return $minLen
    fi
}

function heapify() {
    local largest=$2
    local l=$((2 * $2 + 1))
    local r=$((2 * $2 + 2))
    comparator ${input[$l]} ${input[$largest]} 
    if [ $l -lt $1 -a $? -eq "1" ];then
        largest=$l
    fi
    comparator ${input[$r]} ${input[$largest]}
    if [ $r -lt $1 -a  $? -eq "1" ]
    then
        largest=$r
    fi
    if [ $largest -ne $2 ]
    then
        local a="${input[$2]}"
        input[$2]="${input[$largest]}"
        input[$largest]="$a"
        heapify $1 $largest
    fi
}


function sortByPyramid() {
    local t=$(($count / 2 - 1))
    for ((i = $t; i >=0; i--))
    do
        heapify $count $i
    done
    for ((j = $count-1; j>=0;j--))
    do
        local a="${input[0]}"
        input[0]="${input[$j]}"
        input[$j]="$a"
        heapify $j 0
    done
}


count=0
if [ $# -ne 1 ] # from file or from stdin. if true - stdin else file
then
    while read line
    do
        input[$count]=$line
        count=$(( $count + 1 ))
    done
else
    exec 0<$1
    while read line
    do
        input[$count]=$line
        count=$(( $count + 1 ))
    done
fi

sortByPyramid

for ((i = $count; i >= 0; i--))
do
    echo ${input[$i]}
done

