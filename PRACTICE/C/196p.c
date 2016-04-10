#include<stdio.h>
#include<stdlib.h>
void _print(int pos,int open,int close,int n);
void print(int n);
int i;

main()
	{
		int n;
		printf("Enter N:\n\n");
		scanf("%d",&n);
	
		print(n);
	
	
	
	
	}
	
void print(int n)
	{
		if(n>0)
			{
			
				_print(0,0,0,n);
			}
		printf("%d",i);
	
	
	
	
	}	
	
	
void _print(int pos,int open,int close,int n)
	{
		static char str[130];
		
			if(n==close)
				{
					printf("%s\n\n",str);
					i++;
				}
			else
				
				{
					if(open>close)
						{
							str[pos]='}';
							_print(pos+1,open,close+1,n);
						
						}
					if(open<n)
						{
							str[pos]='{';
							_print(pos+1,open+1,close,n);
						
						}	
				
				
				
				}		
	
	
	
	}	
	
