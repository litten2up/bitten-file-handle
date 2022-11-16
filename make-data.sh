#!/bin/bash
xxd -i -a $1 | sed --expression='s/char .*\[/char data\[/g' > data.h
gcc main.c -o file-creation
./file-creation
