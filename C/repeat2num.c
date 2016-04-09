#include<stdio.h>

void repeat_xor(int *, int );
void repeat_math(int *);
void printRepeating(int *, int );
int main()
	{
	//int a[] = {4, 2, 4, 5, 2, 3, 1};
	int a[] = {6,2,6,5,2,3,1};
	printf("");
	//repeat_math(a);
	printRepeating(a, sizeof(a)/sizeof(a[0]));
	repeat_xor(a, sizeof(a)/sizeof(a[0]));
	return 0;
	}
void repeat_xor(int a[], int size)
		{
		
		printf("\n size : %d", size);
		int n = size;
		int XOR=a[0];
		int X=0, Y=0;
		int set_bit;
		int i;
		for(i=1; i<=n; i++)
			XOR ^=i;
		for(i=1;i<size;i++)
			XOR ^=a[i];
		set_bit = XOR & ~(XOR-1);
		for(i=0; i<size; i++)
			{
				if(a[i] & set_bit  )
					X ^=a[i];
				else	
					Y ^=a[i];
			}
			
		for(i=1; i<=n; i++)
			{
				if(i&set_bit )
					X ^=i;
				else	
					Y ^=i;
			}	
		printf("Repeated numbers: [%d] \t [%d]\n", X, Y);	
		
		
		
		}
		
void printRepeating(int arr[], int size)
{
  int xor = arr[0]; /* Will hold xor of all elements */
  int set_bit_no;  /* Will have only single set bit of xor */
  int i;
  int n = size - 2;
  int x = 0, y = 0;
   
  /* Get the xor of all elements in arr[] and {1, 2 .. n} */
  for(i = 1; i < size; i++)
    xor ^= arr[i];  
  for(i = 1; i <= n; i++)
    xor ^= i;   
 
  /* Get the rightmost set bit in set_bit_no */
  set_bit_no = xor & ~(xor-1);
 
  /* Now divide elements in two sets by comparing rightmost set
   bit of xor with bit at same position in each element. */
  for(i = 0; i < size; i++)
  {
    if(arr[i] & set_bit_no)
      x = x ^ arr[i]; /*XOR of first set in arr[] */
    else
      y = y ^ arr[i]; /*XOR of second set in arr[] */
  }
  for(i = 1; i <= n; i++)
  {
    if(i & set_bit_no)
      x = x ^ i; /*XOR of first set in arr[] and {1, 2, ...n }*/
    else
      y = y ^ i; /*XOR of second set in arr[] and {1, 2, ...n } */
  }
   
  printf("\n The two repeating elements are %d & %d ", x, y);
} 		
void repeat_math(int a[])
		{
			int n = sizeof(a);
			int S = n*(n+1)/2;
			int X ;
			int Y;
			int P, sum=0;
			int N;
			int i;
			for (i=1; i<n;i++)
				N *=i;
			for(i=0;i<n;i++)
				sum +=a[i];
				P *=a[i];
		sum= S - sum;
		P = N / P;
		
		}