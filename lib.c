//lib.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "lib.h"

/*
   Associamo ad un array ** puntatore ogni singola riga.
   char * arr = malloc(sizeof(char));
   while(*(tokenPtr+i)!= ',' && *(tokenPtr+i) != '\0'){
   	*(arr+i) = *(tokenPtr+i); //associo V carattere diverso ad arr 					  //in posizione i.
   	i++;
   }
*/
void ReadFile(FILE * file){
	char *tokenPtr;
	int i=0, j=0;
	file = fopen("records.csv", "r");
	if(file	== NULL){
		printf("File could not be opened");
	}
	else {
		line integer = initializeStruct(max_line, LINE_CHAR);
		printf("\tID \t\tSTRING \t\tINTEGER \t\tFLOAT\n");
		printf(" %s ", tokenPtr+i*max_line);
		while(!feof(file) && i < max_line){
			riga = fgets(stringa,200,file);
			nuova_riga = DeleteWhiteSpace(riga);
			tokenPtr = strtok(nuova_riga, ",");
			//while(tokenPtr != NULL){
				/*printf(" %s \n", ((char *)integer.arr+2+0));*/
				//tokenPtr+i*200+j*max_line;
				//((int*)integer.arr)[i];
				//tokenPtr = strtok(NULL,",");
			//}
			i++;	
		}
		while(*(tokenPtr+j) != ','){
				printf("Token : %c ", *(tokenPtr));
				((char*)integer.arr)[j] = *(tokenPtr+j);
				printf("Pos car: %d, Carattere >> %s \n", j, ((char*)integer.arr));
				j++;
			}
		//printf(" %s ", tokenPtr+1+0);
		fclose(file);
	}
}

/*struct line * FileToStruct(FILE * file, struct line * curr_l){
      struct line * tmp_line = NULL;
      int i=0;
      int val;*/ /*Integer Value to write into the struct*/
      /*char object[10]; /*String that has to write into the struct curr_l*/
      /*int val_2; /*Second integer to write into the struct*/
      /*float f_val; /*Float value to write into the struct*/
      /*tmp_line = malloc(max_line * sizeof(curr_l));
      file = fopen("records.csv", "r");
	if(file	== NULL){
		printf("File could not be opened");
	}
		else{		
			while(fscanf(file, "%d %s %d %f\n", &(tmp_line+i)->val1, (tmp_line+i)->words, &(tmp_line+i)->val2, &(tmp_line+i)->val3)==4){			
			        printf("-> %d <-\n",(tmp_line+i)->val1);
			        i++;
			}
			fclose(file);
		}
	return tmp_line;
}

void PrintStruct(struct line * curr_l){

}
*/

line initializeStruct(size_t size, Datatype data){
	/*I declare a new size_t called realSize of EACH value I want to store into void* data...
	It's initialized to 0*/
	size_t realSize = 0;
	/*Because of 3 different sizes I have to make if...else if...else condition*/
	if(data == LINE_INT){
		realSize = size * sizeof(int); /*Integer as float values take 4 bytes*/
	}
	else if(data == LINE_CHAR){
		realSize = size * sizeof(char);
	}
	else if(data == LINE_FLOAT){
		realSize = size * sizeof(float);
		}
	/*Here I have to inizialize the struct line*/
	line curr_line = {
		.size = size,
		.type = data,
		.arr = malloc(realSize)
	};
	return curr_line;
}

void Ordina(line integer){
	if(integer.type == LINE_INT){
		Ordina_Integer(integer);
	}
	else if(integer.type == LINE_CHAR){
		Ordina_Char(integer);
	}
	else if(integer.type == LINE_FLOAT){
		Ordina_Float(integer);
	}
}

/*ordina integers*/
void Ordina_Integer(line integer){
	int i, key, j;
    	for (i = 1; i < max_line; i++){
        	key = ((int*)integer.arr)[i];
        	j = i - 1;
		while (j >= 0 && ((int*)integer.arr)[j] > key)
		{
		    ((int*)integer.arr)[j + 1] = ((int*)integer.arr)[j];
		    j = j - 1;
		}
		((int*)integer.arr)[j + 1] = key;
    	}
}

/*Ordina characters*/
void Ordina_Char(line integer){
	int i, j;
	char key;
    	for (i = 1; i < max_line; i++){
        	key = ((char*)integer.arr)[i];
        	j = i - 1;
 
		
		while (j >= 0 && ((char*)integer.arr)[j] > key)
		{
		    ((char*)integer.arr)[j + 1] = ((char*)integer.arr)[j];
		    j = j - 1;
		}
		((char*)integer.arr)[j + 1] = key;
    	}
    	

}

/*Ordina Float*/
void Ordina_Float(line integer){
	int i,j;
	float key;
    	for (i = 1; i < max_line; i++){
        	key = ((float*)integer.arr)[i];
        	j = i - 1;
 
		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && ((float*)integer.arr)[j] > key)
		{
		    ((float*)integer.arr)[j + 1] = ((float*)integer.arr)[j];
		    j = j - 1;
		}
		((float*)integer.arr)[j + 1] = key;
    	}
}
void WriteToFile(line integer, line floater, line character, FILE * fp){
       fp = fopen("prova.csv", "w"); /*apro in scrittura*/
       if(fp == NULL){
         perror("File could not be opened.\n");
       }
       else{
             int value_to_write, i = 0;
             printf("Values from struct to destination file...\n");
             while(!feof(fp) && i < max_line){
             	fprintf(fp, "%d %f %c ", ((int*)integer.arr)[i], ((float*)floater.arr)[i], ((char*)character.arr)[i]);
             	i++;
             }
             /*then close the file, once finished.*/
             fclose(fp);
       }
}

char * DeleteWhiteSpace(char *str1){
  char *str2;
  str2=str1;
  while (*str2==' ') str2++;
  if (str2!=str1) memmove(str1,str2,strlen(str2)+1);
  return str2;
}
