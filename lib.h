/*ESERCIZIO 1 - Laboratorio di Algoritmi e Strutture Dati - 
Studenti che collaborano al progetto: 
	Lobascio Giuseppe Pio 
	Mansi Matteo
*/
#ifndef _LIB_H_
#define _LIB_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_line 10
FILE * file;
char stringa[100];
char *riga, *nuova_riga, tempCar;
/*
For this library I thougth about using 2 structs : the first one will help me enumerate and know which type 
I want to cast, while the second only will store each data using void pointers.
*/
typedef enum{
       LINE_INT,
       LINE_CHAR,
       LINE_FLOAT
}Datatype;

typedef struct{
      size_t size; 	/*I'm using size_t because of void pointer.*/
      Datatype type;	/*Type of data from the above structure. The process of take the exactly sizeof will be
                     	easier. 
                     	*/
      void* arr; 	/*Generic array that should be anything it wants.
                        *(*(arr+i*max_line+j))
                    */
}line;

line initializeStruct(size_t size, Datatype data);
void ReadFile(FILE * file);
char * DeleteWhiteSpace(char *RigaCompleta);
/*now I define a function that allows to take and put inside every single dynamic array 
  each value by its type.
  Ex : if i have this row : 0,noto,1234,23.45 -> the function operates on file returning a new struct -> int_arr[0] = 0, char_arr[0] = noto, int_arr2[0] = 1234, float_arr[0] = 23.45
*/
//struct line FileToStruct(FILE * file, struct line curr_l);
//void PrintStruct(struct line curr_l);
void Ordina(line integer);
void Ordina_Integer(line integer);
void Ordina_Float(line floater);
void Ordina_Char(line character);
void WriteToFile(line integer, line floater , line character, FILE* file);
#endif
