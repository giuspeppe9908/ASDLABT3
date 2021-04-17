#include <stdio.h>
#include <stdlib.h>
#define MAX_LINES 6
/*
	Struct & File ptr
*/
/*struct field{
	int id;
	char * field1;
	int field2;
	double field3;
}record;*/

struct v_ptr{
	void * id;
	void * field1;
	void * field2;
	void * field3;
}a;

FILE * fp;
struct field total_records[MAX_LINES];
struct v_ptr data[MAX_LINES];
/*
	Prototype functions
*/
void ReadFile(FILE * fp);
void PrintStruct(struct v_ptr data[]);

