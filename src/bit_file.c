/*
MIT License

Copyright (c) 2022 bitten2up

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "defaultSave.h"	// default savefile
#include "bit_file.h"
#define VERSION 0x01

void writeSave();
int readSave()
{
	FILE *f1 = fopen("bitten.sav", "rb"); // open in binary mode
	char* buffer;
	long saveSize;
	if (f1!=NULL){
		fseek(f1, 0L, SEEK_END);
		saveSize = ftell(f1);
		rewind(f1);
		buffer = calloc(1, saveSize+1);
		if (!buffer)
		{
			fclose(f1);
			fputs("mem alloc failed", stderr);
			return 1;
		}
		if (1!=fread(buffer,saveSize, 1, f1))
		{
			fclose(f1);
			fputs("read failed", stderr);
			return 1;
		}
		// read and printout the data
		printf("header:\n");
		for (int i=0; i<10; i++)
		{
			if (buffer[i] != saveD[i])
			{
				printf("header mismatch");
				writeSave();
			}
			printf("%c",buffer[i]);
		}
		printf("\n");
		printf("Version of game saved: %i\n", buffer[10]);
		// free memory
		fclose(f1);
		free(buffer);
	} // dont write default data to file that already exsits
	else {
		fclose(f1);
		writeSave();
	}
	return 0;
}
void writeSave()
{
	FILE* f1 = fopen("bitten.sav", "wb");
	printf("save data that is being created\n");
	printf("%s", saveD);
	fwrite(saveD, sizeof(char), sizeof(saveD), f1);
	fclose(f1);
	return;
}
