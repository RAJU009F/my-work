#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void alpha(char *t,int len)
	{
		int i=0,j=0,k;
		
		while(*(t+i))
			{
				if((*(t+i)>='a' && *(t+i)<='z')||(*(t+i)>='A' && *(t+i)<='Z'))
					{
						*(t+j)=*(t+i);
						j++;
					
					
					}
				i++;	
			
			
			
			}
			*(t+j)='\0';
			
		printf("%s\n\n",t);	
	
	
	}


main()
	{
		char  t[450];
		
		scanf("%s",t);
		int len=strlen(t)-1;
		alpha(t,len);
		
		
		
	
	
	
	}
