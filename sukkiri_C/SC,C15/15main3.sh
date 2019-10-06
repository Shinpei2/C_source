#!/bin/sh
gcc -c -o 15sub3.o 15sub3.c
gcc -c -o 15main3.o 15main3.c
gcc -o mainapp 15sub3.o 15main3.o
