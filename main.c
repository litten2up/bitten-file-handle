#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "data.h"

int main(){
	FILE *f1 = fopen("test1.zip", "wb");
	printf("data that is being created");
	printf(data);
	printf("\n");
	fwrite(data, sizeof(char), sizeof(data), f1);
	fclose(f1);
	return;
}
