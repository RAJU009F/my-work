//Maximum sum sub array

#include<stdio.h>
//#include<stdlib.h>
void max_sub_array(int *, int );
int main()

{
	
	int array[] = {1,-2, -3, 0 ,-4,-6,7,8};
	//int size = (sizeof(array)/sizeof(array[0]));
	max_sub_array(array,8);
	return 0;
	
}
 
 void max_sub_array(int arr[], int n)
 {
	 int i, maxsum=0, sum=0 , st, tst, end;
	 for(i=0; i<n;i++)
	 {
		 sum = sum +arr[i];
		 if(sum<0)
		 {
			 sum = 0;

			 st = i+1;
		 }
		 else	
		 {
			 
			 if(sum>maxsum)
			 {
				 maxsum = sum;
				 end = i;
				 
			 }
		 }
		 
		 
		 
	 }
	 
	 printf(" %d, ", maxsum);
	 
	 
 }

