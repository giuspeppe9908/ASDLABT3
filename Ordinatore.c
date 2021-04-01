#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "lib.h"

int main(){
	int i;
        printf("--->> FILE ORDINATOR <<---\n");
        printf("Reading from file...\n");
        ReadFile(file);
        /*srand(time(NULL));
        char abc[26]="abcdefghijklmnopqrstuvwxyz";
        line integer = initializeStruct(max_line, LINE_INT);
        line floater = initializeStruct(max_line, LINE_FLOAT);
        line character = initializeStruct(max_line, LINE_CHAR);
        
        for(i = 0; i < max_line; i++){
            ((int*)integer.arr)[i] = rand()%100+1; 
            ((float*)floater.arr)[i] = rand()%100+1;
            ((char*)character.arr)[i] = abc[rand() % (sizeof(abc) - 1)];
        }
        
        for(i = 0; i < max_line; i++){
           printf(" Valore INT : %d, Valore Float : %f, Valore Char: %c \n", ((int*)integer.arr)[i], ((float*)floater.arr)[i], ((char*)character.arr)[i]);
           
        }
        printf("Starting ordering...\n");
        Ordina(integer);
        Ordina(floater);
        Ordina(character);
        printf("End ordering.\n Check if ordered...\n");
        
        for(i = 0; i < max_line; i++){
           printf(" Valore INT : %d , Valore Float : %f , Valore Char : %c \n", ((int*)integer.arr)[i], ((float*)floater.arr)[i], ((char*)character.arr)[i]);
        }
        WriteToFile(integer, floater, character, file);
        */
        printf("End of Program\n");
}
