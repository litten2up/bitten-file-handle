#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "defaultSave.h"	// default savefile
#include "bit_file.h"
#define VERSION 0x01

int readSave(){
	FILE *f1 = fopen("bitten.sav", "rb"); // open in binary mode
	if (f1!=NULL){
		
		return 0;
	} // dont write default data to file that already exsits
	f1 = fopen("bitten.sav", "wb");
	printf("save data that is being created\n");
	printf("%s", saveD);
	printf("\n");
	fwrite(saveD, sizeof(char), sizeof(saveD), f1);
	fclose(f1);
	return 0;
}
