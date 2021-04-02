#include <stdio.h>
#include <stdlib.h>
#define MAX_LINES 6
/*
	Struct & File ptr
*/
struct field{
	int id[100];
	char field1[100];
	int field2[100];
	double field3[100];
}record;

FILE * fp;
struct field total_records[MAX_LINES];

/*
	Prototype functions
*/
void ReadFile(FILE * fp);
void PrintStruct(struct field total_records[]);

