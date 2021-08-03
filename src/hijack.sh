#!/bin/sh
gcc -Dmalloc=smalloc -Dfree=sfree -c $1.c
gcc -c safe_mem.c
gcc $1.o safe_mem.o -o hijack.out

rm $1.o safe_mem.o  
