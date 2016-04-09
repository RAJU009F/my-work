#include<stdio.h>
void prodarr(int arr[], int prod[], int n)
	{
		int i, temp=1;
		
		for(i=0;i<n;i++)
			{
				prod[i] = temp;
				temp = temp *arr[i];
				//printf ("[%d %d ]\t", prod[i], i)	;
			
			}
			temp = 1;
			//printArray(prod, n);
			for(i=n-1; i>=0;i--)
				{
					prod[i] = prod[i] *temp;
					temp = temp * arr[i];
				//printf ("[%d %d ]\t", prod[i], i)	;
				}
	
	//printArray(prod, n);
	}
printArray(int Arr[], int n)
	{
		int i;
		for(i=0;i<n;i++)
			{
				printf("[%d]\t",Arr[i]);
			
			}
	printf("\n\n");
	
	}

int main()
	{
		int arr[] = {10, 3, 5, 6, 2};
		int n=sizeof(arr)/sizeof(arr[0]);
		int prod[n];	
		
		printArray(arr, n);
		prodarr( arr, prod,  n);
		
		printArray(prod, n);
	return 0;
	}