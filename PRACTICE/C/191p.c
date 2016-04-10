#include<stdio.h>
#include<stdlib.h>

int trail(char *,int );

main()
	{
		int i=5;
		printf("%d\n",i++*i--);
		
		char c='a';
		printf("%d\n",c);
		int t=((int)c++);
		printf("%d\n",t);
		
		char c1[455];
		char *p;
		gets(c1);
		
		for(p=c1;*p!='\0';p++);
		printf("%d",p-c1);
			char p2[100];
		printf("\n\nmax%d\n\n",trail(p2,10));				
			
		
	
	}
int trail(char *ch,int max)
	{
		int nch=0;char c;
		max=max-1;
		while((c=getchar())!=EOF)
			{
				if(c=='\n')
					break;
				if(nch<max)
					{
						*(ch+nch)=c;
						nch=nch+1;
					
					}
			}			
			
			
		return nch;
	} 
			
			
			
		
	
	
	
	
	
		
	
