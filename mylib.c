#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "mylib.h"

void ReadFile(FILE * fp){
	fp = fopen("records.csv","r");
	if(fp == NULL)
		perror("Error occured while opening the FILE.\n");
	else{
		/*Create buffer of 1024 chars*/
		char buffer[1024];
		/* row_counter && field_counter*/
		int row_count = 0;
		int field_count = 0;
		int i=0;
		datas = &data[0];//(struct v_ptr *)malloc(MAX_LINES * sizeof(struct v_ptr));
		printf("### READING FROM FILE ###\n");
		/*Using fgets to hold into buffer from file*/
		while(fgets(buffer, 1024, fp) && i < MAX_LINES){
			/*printing on screen the content of the buffer*/
			printf("Record -> %s \n", buffer);
			field_count = 0;
			row_count++;
			/* creating a char * ptr to assing strtok(NULL, ",");*/
			char * ptr = strtok(buffer, ",");
			/*Now store into the struct total_record of type record.*/
			while(ptr!=NULL){
				if(field_count == 0){
					//total_records[i].id = atoi(ptr);
					//data[i].id = malloc(MAX_LINES * sizeof(ptr));
					datas[i].id = malloc(MAX_LINES * sizeof(ptr));
					*(int*)datas[i].id = atoi(ptr);
					//*(int*)data[i].id = atoi(ptr);//total_records[i].id;
				}
				if(field_count == 1){
					//total_records[i].field1 = malloc(MAX_LINES * sizeof(ptr));
					datas[i].field1 = malloc(MAX_LINES * sizeof(ptr));
					//strcpy(total_records[i].field1, ptr);
					strcpy((char*)datas[i].field1, ptr);//total_records[i].field1);
				}
				if(field_count == 2){
					//total_records[i].field2 = atoi(ptr);
					datas[i].field2 = malloc(MAX_LINES * sizeof(ptr));
					*(int*)datas[i].field2 = atoi(ptr);//total_records[i].field2;
				}
				if(field_count == 3){
					//total_records[i].field3 = atof(ptr);
					datas[i].field3 = malloc(MAX_LINES * sizeof(ptr));
					*(double*)datas[i].field3 = atof(ptr);//total_records[i].field3;
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

void PrintStruct(struct v_ptr * datas){
	printf("NOW STRUCT OF POINTER CONTAINS...\n");
	int i = 0;
	printf("|\t ID \t|\t STRING \t|\t INTEGER \t|\t FLOAT \t\t|\n");
	while( i < MAX_LINES){
		printf("|\t %d \t|\t %10s \t|\t %10d \t|\t %10.5f \t|\n", *(int*)datas[i].id, (char*)datas[i].field1, *(int*)datas[i].field2, *(double*)datas[i].field3);
			i++;	
		}
	printf("-----------------------------------\n");
}

void Ordina(struct v_ptr * datas, int count){
	if(count == 1){
		Ordina_Integer(datas);
	}
	else if(count == 2){
		Ordina_String(datas);
	}
	else if(count == 3){
		Ordina_Float(datas);
	}
}

void Ordina_Integer(struct v_ptr * integer){
	int i, key, j;
    	for (i = 1; i < MAX_LINES; i++){
        	key = *((int*)integer[i].field2);
        	j = i - 1;
		while (j >= 0 && *((int*)integer[j].field2) > key)
		{
		    *((int*)integer[j+1].field2) = *((int*)integer[j].field2);
		    j = j - 1;
		}
		*((int*)integer[j + 1].field2) = key;
    	}
}

/*Ordina characters*/
void Ordina_String(struct v_ptr * string){
	int i, j;
	char * key = malloc(MAX_LINES * sizeof(char*));
    	for (i = 1; i < MAX_LINES; i++){
        	strcpy(key,(char*)string[i].field1);
        	j = i - 1;
		while (j >= 0 && strcmp((char*)string[j].field1,key)>0)
		{
		    strcpy((char*)string[j+1].field1,(char*)string[j].field1);
		    //((char*)integer.arr)[j + 1] = ((char*)integer.arr)[j];
		    j = j - 1;
		}
		strcpy((char*)string[j+1].field1, key);
		//((char*)integer.arr)[j + 1] = key;
    	}
}
 
void Ordina_Float(struct v_ptr * floater){
	int i,j;
	float key;
    	for (i = 0; i < MAX_LINES; i++){
        	key = *((double*)floater[i].field3);
        	j = i - 1;
		while (j >= 0 && *((double*)floater[j].field3) > key)
		{
		    *((double*)floater[j + 1].field3) = *((double*)floater[j].field3);
		    j = j - 1;
		}
		*((double*)floater[j + 1].field3) = key;
    	}
}

void MergeSort(struct v_ptr * datas, int p, int r){
	if( p < r ){	
		int q = (p + r)/2;
		//MergeSort(datas, p, q);
		//MergeSort(datas, q + 1, r);
		MergeInteger(datas, p, q, r);
	}
}

void MergeInteger(struct v_ptr * datas, int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1];
	int R[n2];
	/*L[0] = *((int*)datas[0].field2);
	printf(" Dato copiato : %d \n", L[0]);*/
	//struct v_ptr * L = malloc(n1 * sizeof(*datas));
	//struct v_ptr * R = malloc(n2 * sizeof(*datas));
	int i, j;
	for(i = 1; i < n1; i++){
		L[i] = *((int*)datas[p + i - 1].field2);
	}
	
	for(j = 1; j < n2; j++){
		R[j] = *((int*)datas[q + j].field2);
	}
	i = 1, j = 1;
	int k = p;
	for(; k < r; k++){
		if(L[i] <= R[j]){
			*((int*)datas[k].field2) = L[i];
			i = i + 1;
		}
		else{ 
		    	*((int*)datas[k].field2) = R[j];
			j = j + 1;
		}
	}	
	/*int right;
	int left;
	int k;
	int i;
	int aux[MAX_LINES];
	//double aux2[MAX_LINES];
	//char aux3[MAX_LINES];
    	k = 0;
   	left = p;
    	right = q + 1;
	
    	/*for (k = 0;  (left <= q) && (right <= r);  ++k) {
        	if(*((int*)datas[left].field2) <= *((int*)datas[right].field2)){
            		aux[k] = *((int*)datas[left++].field2);
        	}
        	else{
            		aux[k] = *((int*)datas[right++].field2);
        	}
    	}

    	for(left = p;  left <= q;  ++left, ++k){
        	aux[k] = *((int*)datas[left].field2);
	}
    	for(right;  right <= r;  ++right, ++k){
        	aux[k] = *((int*)datas[right].field2);
	}
    	k = p;
    	i = 0;
    	for (k;  k <= r;  ++k, ++i){
        	*((int*)datas[k].field2) = aux[i];
	}*/
}
