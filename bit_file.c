#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "defaultSave.h"	// default savefile
#include "bit_file.h"
#define VERSION 0x01

int readSave(){
	FILE *f1 = fopen("bitten.sav", "rb"); // open in binary mode
	char buffer[];
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
		printf("Version of game saved: %c", buffer[1]);
		// free memory
		fclose(f1);
		free(buffer);
	} // dont write default data to file that already exsits
	else
	{
		f1 = fopen("bitten.sav", "wb");
		printf("save data that is being created\n");
		printf("%s", saveD);
		printf("\n");
		fwrite(saveD, sizeof(char), sizeof(saveD), f1);
		fclose(f1);
	}
	return 0;
}
