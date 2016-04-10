#include<stdio.h>

#include<stdlib.h>
int i=0;

void _printp(int pos, int open,int close,int n)
	{
		static char  c[1000];
		if(close==n)
			{
				printf("%s\n\n",c);
				i++;
				
			
			}
			
		else
			{
				if(close<open)
					{
						c[pos]='}';
						_printp(pos+1,open,close+1,n);	
						
					}	
				 if(open<n)
					{
						c[pos]='{';
						_printp(pos+1,open+1,close,n);
					
					
					
					
					}
			
			
			
			
			}	
	
	
	
	
	}
	
	
void printP(int n)
	{
		if(n>1)
			{
				
				_printp(0,0,0,n);
				printf("\n\n%d\n\n",i);
				
			}
	
	
	
	}


main()
	{
	
		int n;
		printf("Enter N:\n\n");
		scanf("%d",&n);
		printP(n);
	
	
	
	}


