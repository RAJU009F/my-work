#include<stdio.h>
#include<stdlib.h>

void f1(char *x)
 {
	x++;
	*x = 'a';
}
int main() 
{
	char str[] = "hello";
	f1(str);
	printf("%s", str);
}
