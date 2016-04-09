#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void printParenthsis(int pos, int N, int close, int open)
{
	static char str[MAX];
	if(close==N)
	{printf("%s\n",str);
return;}
	else
	{
		if(open>close)
		{
		str[pos] = '}';
		printParenthsis( pos+1,  N,  close+1,  open);
		}
		if(open<N)
		{
			str[pos] = '{';
		printParenthsis( pos+1,  N, close,  open+1);
			
		}
		
		
	}
	
	
	
}
int main()
	{
	int N;
	
	scanf("%d",&N);
	
	printParenthsis(0,N,0,0);
	
	
	}