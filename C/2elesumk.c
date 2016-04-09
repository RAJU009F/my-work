#include<stdio.h>

void sumk(int *, int, int);

int main()
	{
	int a[] = {1,2,3,4,5,6,7,8,9};
	sumk(a, sizeof(a)/sizeof(a[0]), 15);
	
	return 0;
	}
void sumk(int a[],  int size, int k)
		{
			int i, j,temp;
			for(i=0,j=size-1; i<j;)
			{
				temp = a[i] + a[j];
				if(temp == k)
					{
					printf(" %d + %d = %d \n\n ",a[i], a[j],k);
					return;
					}
				else
					{
						if (temp>k)
							j--;
						else
							i++;
					
					}
			
			}
		
		
		}