
// UNION and INTERSECTION OF TWO ARRAYS

#include<stdio.h>
void Union(int *, int, int *, int);
void intersection(int *,  int ,int *, int );
int main()
	{
	int a[]= {1, 3, 4, 5, 7};
	int b[] = {2, 3, 5, 6};
	
	int m = sizeof(a)/sizeof(a[0]);
	int n = sizeof(b)/sizeof(b[0]);
	Union(a, m ,b ,n);
	intersection(a, m ,b ,n);
	}
void Union(int *a, int m ,int *b ,int n)
{
	int i=0, j = 0;
	printf("UNION of two arrays:\n\n");
	while(i<m && j< n)
	{
		if(a[i]>b[j])
		{
			printf("\t[%d]",b[j]);
			j++;
		}else if(a[i]<b[j])
		{
			printf("\t[%d]",a[i]);
			i++;
			
		}else{
			
			printf("\t[%d]",a[i]);
			i++;
			j++;
		}
		
		
		
	}
	while(i<m)
	{
		printf("\t[%d]",a[i]);
		i++;
		
	}while(j<n)
	{
			printf("\t[%d]",b[j]);
			j++;
	}
	
	
}
void intersection(int *a, int m, int *b, int n)
{
	printf("\n\n intersection of two arrays:\n\n");
	int i=0, j=0;
	while(i<m && j<n)
	{
		if(a[i]<b[j])
		{
			i++;
		}else if(a[i] > b[j])
				j++;
		else
		{
			printf("\t[%d]",a[i]);
			i++;
			j++;
		}
		
		
	}
	
	
}
