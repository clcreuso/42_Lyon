#! /bin/bash

mkdir ./tmp

cat $1 > ./tmp/cat.output
./ft_cat $1 > ./tmp/ft_cat.output

diff ./tmp/cat.output ./tmp/ft_cat.output

rm -rf ./tmp
