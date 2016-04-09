#include<iostream>
#include<sort>
using namespace std;

int find_lenght_longest_consecutives(A, size);
{
	
	sort(A);
	int max, len=0; min;
	for (i=0;i<size; i++)
	{	
		if(A[i]+1==A[i+1])
			len += 1;
		else{
			
				if(max<len)
					max =len;
				len=0;
			
		}
		
		
	}
	return max;
	
}


int main()
	{
	
	int A[] = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
		int size = sizeof(A)/sizeof(A[0]);
		
		int len = find_lenght_longest_consecutives(A, size);
		cout<<len;
		
	
	}
