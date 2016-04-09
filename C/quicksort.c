// Quick sort non recursive

#include<stdio.h>
void quicksort(int a[], int , int);
main()
{
	int size,a[100],i;
	
	scanf("%d", &size);
	for(i=0; i<size; i++)
	{
		scanf("%d", &a[i]);
	}
	quicksort(a,0, size-1);
	for( i=0; i<size; i++)
	{
		printf("%d\t", a[i]);
	}
	
	
}

void quicksort(int a[100], int first, int last)
{
	int pivot, i, j, temp;
	//printf("started");
	if(first<last)
	{
		i = first;
		j = last ;
		pivot = last;
		while(i<j)
		{
			//printf("started while");
			while(a[i]<=a[pivot]&&i<last)
				{i++;}
			while(a[j]>a[pivot])
				{j--;}
			if(i<j){
			temp =a[i];
			a[i] = a[j];
			a[j] = temp;
				//printf("exchanged i , j ");
			}	
			}
			temp = a[pivot];
			a[pivot] = a[i];
			a[i] = temp ;
				//printf("exchanged pivit with i");
			quicksort(a, first, i-1);
			quicksort(a,i+1, last);
		
		
		
	
	
	}



}
