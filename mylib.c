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
					total_records[i].id[i] = atoi(ptr);
				}
				if(field_count == 1){
					strcpy(total_records[i].field1, ptr);
				}
				if(field_count == 2){
					total_records[i].field2[i] = atoi(ptr);
				}
				if(field_count == 3){
					total_records[i].field3[i] = atof(ptr);
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
	}
}

void PrintStruct(struct field total_records[]){
	printf("NOW STRUCTURE CONTAINS...\n");
	for(int i = 0; i < MAX_LINES; i++){
	printf(" ID : %d | FIELD1: %s | FIELD2: %d | FIELD3: %f|\n",total_records[i].id[i], total_records[i].field1, total_records[i].field2[i], total_records[i].field3[i]);
	}
}
