#include<stdio.h>

// print elements in a 2D array diagonally

// step -1 : Initalize count = R+C-1, r=0,c=0;
// step -2 : do while coutn >=0
// step -3 :  do print all elemnts in array limits by chacking the position(i,j) and update i=i-1 and j=j+1
// step -4 : update r = r+1  and  c=0 if r<R-1 else c++
// step -5 : decremant count-- 


int isSafe(int i, int j, int R, int C)
{
	return (i>=0 && i<R) &&(j>=0 &&j<C);
}
void printDiagonal(int M[5][4], int R,  int C)
{
	int i,j;
	int c=0,r=0,flag;
	int count = R+C-1;
	while(count)  // we know total nof iterations = R+C-1
	{
		i=r;
		j=c;
		flag = 1;
		while(flag)
		{
			// check if  pos(i,j) under bound
			if(isSafe(i,j, R,C))
			{
				printf("%d \t",M[i][j]);
				i--;
				j++;
			}else{
				
				flag=0;
				
			}
			
		}
		printf("\n");
		
		if(r<R-1)
		{
			r++;
			c=0;
		}else
		{
			c++;
		}
		count--;
		
		
	}
	
	
	
}
int main()
	{
	int R=5, C=4;
	int M[5][4]={{1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20},
    };
	printDiagonal(M,R,C);
	return 0;
	}
