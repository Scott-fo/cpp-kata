#!/bin/bash

latest=$(ls -vd kata/Day* 2>/dev/null | head -1)

num=${latest#kata/Day}

if [ -z "$num" ]; then
    num=1
else
    num=$((num + 1))
fi

mkdir -p kata/Day$num

DS=("array_list" "linked_list" "binary_tree" "quick_sort" "bubble_sort")

cp templates/*.cpp kata/Day$num/

