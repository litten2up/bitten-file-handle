#!/bin/bash
xxd -i -a $1 | sed --expression='s/char .*\[/char saveD\[/g' > data.h
gcc main.c -o file-creation
./file-creation
