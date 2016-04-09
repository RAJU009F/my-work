#include<stdio.h>
#include<stdlib.h>

void printrepeet(int a[], int size)
	{
		printf("\n size : %d\n", size);
	int XOR=a[0];
	int n=size-2;
	int set_bit, X=0, Y=0;
	int i;
	for(i=1; i<size; i++)
		{
			XOR ^=a[i];
		
		}
	for (i=1; i<=n;i++)
		XOR ^=i;	
	
	set_bit = XOR & ~(XOR-1);
	for(i=0;i<size;i++)
		{
			if(set_bit & a[i]){
			X = X^a[i];}
			else{
				Y= Y ^a[i];
			}
			
		}
		for (i=1;i<=n;i++)
			{
			
			if(set_bit & i){
			X = X ^i;}
			else{
				Y= Y ^i;
			}
			
			}
			
			printf("%d, %d", X, Y);
	}
int main()
	{
	int a[] = {4, 2, 5, 5, 3, 3, 1};
	printrepeet(a, sizeof(a)/sizeof(a[0]));
	return 0;
	}
	
	
	
	
	
	
	
