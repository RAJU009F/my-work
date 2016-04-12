#include<stdlib.h>
#include<stdio.h>
#include<string.h>
// Example Tower of Honoi
// Description: move n plates from A to B using C as Auxialary and no higher plate on lower plate
// Recurrence Relation:  T(n) = 2T(n-1) + O(n)  
// Complexity: O(n*2^n)



void displayTowers(int a[5],int b[5],int c[5],int n)
{	int i;
	for(i=0;i<n;i++)
		{
			printf("[%d]\t[%d]\t[%d] \n",a[i],b[i],c[i]);
		}
}
void doTowerofHonoi(int a[5], int b[5], int c[5], int n)
{
	if(n==1)
	{
		b[n-1]=a[n-1];
		a[n-1] = 0;
		return;
	}
	doTowerofHonoi(a,c,b,n-1);
	c[n-1] = a[n-1];
	a[n-1] =0;
	doTowerofHonoi(c,b, a, n-1);
	b[n-1] = c[n-1];
	c[n-1] = 0;
	
	
}

int main()
	{
	
	int a[] = {1,2,3,4,5};
	int b[5],c[5];
	int n=5;
	memset(b,0,sizeof(b));
	memset(c, 0 , sizeof(c));
	printf("Before \nT-A\tT-B\tT-C\n");
	displayTowers(a,b,c,n);
	doTowerofHonoi(a, b, c, n);
	printf("After \nT-A\tT-B\tT-C\n");
	displayTowers(a,b,c,n);

	return 0;
	
	}
/*
output:-
Before
T-A     T-B     T-C
[1]     [0]     [0]
[2]     [0]     [0]
[3]     [0]     [0]
[4]     [0]     [0]
[5]     [0]     [0]
After
T-A     T-B     T-C
[0]     [1]     [0]
[0]     [2]     [0]
[0]     [3]     [0]
[0]     [4]     [0]
[0]     [5]     [0]



*/	
	