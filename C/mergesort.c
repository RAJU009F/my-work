// MERGE Sort

#include<stdio.h>
#define MAX 100
void partition(int a[], int, int);
void mergesort(int a[], int , int, int);

#define MAX 100
main()
{
	int a[MAX], size, i, j;
	
	scanf("%d",&size);
	for(i=0; i< size; i++)
	{
		scanf("%d",&a[i]);
	
	}
	
	partition(a, 0, size-1);
	
	for(i=0; i< size; i++){
		printf("%d\t",a[i]);}



}
void partition(int a[MAX], int low, int high){
	int mid;
	if(low<high)
	{
	mid = (low + high)/2;
	partition(a, low, mid);
	partition(a, mid+1, high);
	mergesort(a, low, mid, high);
	//printf("mmmmmm");
	}
printf("bbbbbbbbbbbbbbmmmmmm");
}
void mergesort( int a[MAX], int low,  int mid, int high)
{
	int temp[MAX], i, j, k , l, m ;
	l = low;
	i = low;
	m = mid + 1;
	//printf("mmmmmm");
	while((l<=mid) && (m<=high))
	{
		if ( a[l]<= a[m])
			{
				temp[i] = a[l];
				l++;
			}else{
			
				temp[i] = a[m];
				m++;
			}
			i++;
	}
	
	if(l > mid)
		{
			for(k=m; k<=high; k++)
			temp[i] = a[k];
			i++;
		}else{
			for(k=l;k<=mid;k++)
			{
				temp[i] = a[k];
				i++;
			}
		
		}
		
		for(k=low; k<=high; k++ )
		{
			a[k] = temp[k];
		
		}
	




}