#!/bin/bash

latest=$(ls -vd kata/Day* 2>/dev/null | head -1)

num=${latest#kata/Day}

if [ -z "$num" ]; then
    num=1
else
    num=$((num + 1))
fi

mkdir -p kata/Day$num

cp templates/*.* kata/Day$num/

