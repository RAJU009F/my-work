// memory format

#include<stdio.h>
void show_mem(char *mem, int size)
	{
		int i=0;
		for(i=0;i<size;i++)
			{
			printf("\t%x",mem+i);
			}
		printf("\n");	
	
	}

int main()

{
int i;
float f;
double d;
char c;
int *pi;
void *pv;
show_mem((char * )&i, sizeof(i));
show_mem((char * )&f, sizeof(f));
show_mem((char * )&d, sizeof(d));
show_mem((char * )&c, sizeof(c));
show_mem((char * )&pi, sizeof(pi));
show_mem((char * )&pv, sizeof(pv));
return 0;
}