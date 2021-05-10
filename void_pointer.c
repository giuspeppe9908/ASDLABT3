#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "mylib.h"

int main(){
	ReadFile(fp);
	//sleep(1);
	PrintStruct(datas);
	//printf("Now applying Merge-BinaryInsertionSort...\n");
	//srand(time(NULL));
	int count = 1;//rand() % 3+1;//per non avere ripetizioni.
	printf(" Tipo su cui ordino : %d\n", count);
	//Ordina(datas, count);
	//datas->field2 = malloc(MAX_LINES * sizeof(int*));
	p = 0;
	r = MAX_LINES;
	if(count == 1){
	 MergeSort(datas, p, r);
	 PrintStruct(datas);
	}
	return 0;
}
