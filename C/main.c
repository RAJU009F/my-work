#include<stdio.h>

void fun()
{
	static int i=0;
	printf("%d",i);
	i++;
}
int main()
	{
	static int i=0;
	int a=6;
	int *ptr;
	ptr = &a;
	printf("%i\n\n", ptr);
	printf("%i",*ptr);
	if(i>10)
		return;
	//main();
	//#fun();
	//#fun();
	return 0;
	}