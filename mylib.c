#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "mylib.h"


void ReadFile(FILE * fp){
	fp = fopen("prova.csv","r");
	if(fp == NULL)
		perror("Error occured while opening the FILE.\n");
	else{
		/*Create buffer of 1024 chars*/
		char buffer[1024];
		/* row_counter && field_counter*/
		int row_count = 0;
		int field_count = 0;
		int i=0;
		printf("### READING FROM FILE ###\n");
		/*Using fgets to hold into buffer from file*/
		while(fgets(buffer, 1024, fp)){
			/*printing on screen the content of the buffer*/
			printf("%s \n", buffer);
			field_count = 0;
			row_count++;
			/* creating a char * ptr to assing strtok(NULL, ",");*/
			char * ptr = strtok(buffer, ",");
			/*Now store into the struct total_record of type record.*/
			while(ptr){
				if(field_count == 0){
					//total_records[i].id = atoi(ptr);
					data[i].id = malloc(MAX_LINES * sizeof(ptr));
					*(int*)data[i].id = atoi(ptr);//total_records[i].id;
				}
				if(field_count == 1){
					//total_records[i].field1 = malloc(MAX_LINES * sizeof(ptr));
					data[i].field1 = malloc(MAX_LINES * sizeof(ptr));
					//strcpy(total_records[i].field1, ptr);
					strcpy((char*)data[i].field1, ptr);//total_records[i].field1);
				}
				if(field_count == 2){
					//total_records[i].field2 = atoi(ptr);
					data[i].field2 = malloc(MAX_LINES * sizeof(ptr));
					*(int*)data[i].field2 = atoi(ptr);//total_records[i].field2;
				}
				if(field_count == 3){
					//total_records[i].field3 = atof(ptr);
					data[i].field3 = malloc(MAX_LINES * sizeof(ptr));
					*(double*)data[i].field3 = atof(ptr);//total_records[i].field3;
				}
				ptr = strtok(NULL, ",");
				field_count++;
			}
			i++;
		}
		printf("Close the file then print struct.\n");
		fclose(fp);
		sleep(1);
		printf("########################\n");
		//printf("Stampa contenuto void pointer...\n");
		
	}
}

void PrintStruct(struct v_ptr data[]){
	printf("NOW STRUCT OF POINTER CONTAINS...\n");
	int i = 0;
	while( i < MAX_LINES){
		printf(" ID : %d , STRING : %s, INTEGER : %d, FLOAT : %f.\n", *(int*)data[i].id, (char*)data[i].field1, *(int*)data[i].field2, *(double*)data[i].field3);
			i++;	
		}
}
