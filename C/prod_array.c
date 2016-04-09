#include<stdio.h>
void max_prod_array(int *, int );
int main()
{
	//int a[] = {6, -3, -10, 0, 2};
	//int a[] = {-1, -3, -10, 0, 60};
	int a[] =   {1, -2, -3, 0, 7, -8, -2};
	int size = sizeof(a)/sizeof(a[0]);
	
	max_prod_array(a, size);


}

void max_prod_array(int *a, int size)
{
	int i, max =0, prod = 1, st=0,tst=0, end=0;
		for(i=0;i<size; i++)
		{
			prod = prod * a[i];
			if(prod> max)
			{
				max=prod;
				end = i;
				st = tst;
				
			}else if (a[i] ==0)
			{
				prod = 1;
				tst = i+1;
				
				
			}
			
			
			
		}
		
		printf("prod_max:%d, stat:%d, end: %d\n\n",max, st, end);
	
	
	
}