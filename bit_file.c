#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "data.h"
#include "bit_file.h"

int readSave(){
	FILE *f1 = fopen("bitten.sav", "rb");
	if (f1!=NULL){return 0;}
	f1 = fopen("bitten.sav", "wb");
	printf("save data that is being created\n");
	printf("%s", saveD);
	printf("\n");
	fwrite(saveD, sizeof(char), sizeof(saveD), f1);
	fclose(f1);
	return 0;
}
