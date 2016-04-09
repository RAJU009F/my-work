/* Maximum sum sub array*/
#include<stdio.h>
#include<stdlib.h>
void max_sub_array(int *, int );
int main()

{
	
	int array[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int size = (sizeof(array)/sizeof(array[0]));
	max_sub_array(array,size);
	return 0;
	
}
 
 void max_sub_array(int arr[], int n)
 {
	 int i, maxsum=0, sum=0 , st=0, tst, end;
	 for(i=0; i<n;i++)
	 {
		 sum = sum +arr[i];
		 if(sum<0)
		 {
			 sum = 0;

			 tst = i+1;
		 }
		 else	
		 {
			 
			 if(sum>maxsum)
			 {
				 maxsum = sum;
				 end = i;
				 st=tst ;
			 }
		 }
		 
		 
		 
	 }
	 
	 printf(" sum:%d, start=%d, end=%d ", maxsum, st, end);
	 
	 
 }

