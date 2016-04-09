#include<stdio.h>
#include<stdlib.h>

// search element in  a sorted(row wise and column wise) array

int  searchElement(int A[4][4],int n, int ele )
	{
	
		int i=0; 
		int j=n-1;
		while(i<n && j>=0)
			{
				if(A[i][j]==ele)
						return 1;
				else if(A[i][j] < ele )
						i++;
				else
						j--;
			
			
			}
	
	return 0;
	
	
	}


int main()
	{
		int A[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
				  
		if(searchElement(A, 4, 39))
			printf("found element\n");
		else
			printf("element not exists\n");
		
		if(searchElement(A, 4, 34))
			printf("found element");
		else
			printf("element not exists");
	
	
	}