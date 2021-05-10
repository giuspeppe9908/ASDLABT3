#include <stdio.h>
#include <stdlib.h>
#define MAX_LINES 20
/*
	Struct & File ptr
*/
struct v_ptr{
	void * id;
	void * field1;
	void * field2;
	void * field3;
}a;

FILE * fp;
int p;
int r;
//struct field total_records[MAX_LINES];
struct v_ptr data[MAX_LINES];
struct v_ptr * datas;

/*
	Prototype functions
*/
void ReadFile(FILE * fp);
void PrintStruct(struct v_ptr * datas);
void Ordina(struct v_ptr * datas, int count);
void Ordina_Integer(struct v_ptr * integer);
void Ordina_String(struct v_ptr * string);
void Ordina_Float(struct v_ptr * floater);
void MergeSort(struct v_ptr * datas, int p, int r);
void MergeInteger(struct v_ptr * datas, int p, int q, int r);
