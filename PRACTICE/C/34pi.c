#include<stdlib.h>
#include<stdio.h>
#define Y 1
#define N 0
void rev(char *str,int l,int h)
	{
		 
		while(l<h)
			{
				str[l]^=str[h];
				str[h]^=str[l];
				str[l]^=str[h];
				l++;
				--h;
				
			
			}
	
	
	
	
	}
	
int words(char *str)
	{
		int count=0;
		int state=Y;
		while(*str!='\0')
			{
				if(*str==' ')
					{
						state=Y;
					
					
					}
				else if(state==Y )
					{
						state=N;
						count++;
					
					}	
					
					str++;
			
			
			
			
			}
		return count;
	
	
	
	}	
	
void revw(char *str,int l,int h)
	{
		
		
			while(h>=l)
				{
					printf("%c",str[h]);
					--h;
				}
			printf(" ");	
			
	
	
	}	

main()
	{
		char str[100];
		printf("Enter string::\n\n");
		scanf("%[^\n]s",str);
		
		int len=strlen(str)-1;
		rev(str,0,len);
		puts(str);
		printf("No of Words:: %d \n\n",words(str));
		int i=0;
		int start=0,end;
		for(start=end=0;end<=len;end++)	
			{
				if(str[end]!=' ')
					{
						start=end;
						while(str[end]!=' ')
							{
								end++;
							
							
							}
							end--;
							
							revw(str,start,end);
							
					
					
					
					
					}
			
			
			}
		
	
	
	}
