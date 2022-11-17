#!/bin/bash

#xxd -i -a $1 | sed --expression='s/char .*\[/char saveD\[/g' > defaultSave.h
gcc main.c bit_file.c -o file-creation && ./file-creation
