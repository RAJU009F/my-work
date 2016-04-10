#include<stdio.h>
#include<stdlib.h>

int match_util(char *str,char *test)
	{
		if(*str=='\0' && *test=='\0')
			return 1;
			
		if(*test=='*'&&*(test+1)!='\0'&&*str=='\0')
			return 0;
			
			
		if(*str==*test || *test=='?')
			return match_util(str+1,test+1);
			
		else if(*test=='*')
			return match_util(str+1,test)||match_util(str,test+1);			
	
	return 0;
	
	}


void match(char *str,char *test)
	{
		if(match_util(str,test))
			printf("%s\t%s\n",test,str);
			
		if(*test=='^' && match_util(str+1,test+1))
				printf("%s\t%s\n",test,str);
			
		int len=strlen(test)-1;	
		*(test+len-2)='\0';
		if()	
			
				
			
					
	
	
	
	
	}
main()
	{
		char a[4][100];
		int i=0,j=0;
		char s[100];
		printf("Enter Words:");
		
		while(i<4)
			{
			
			scanf("%s",&a[i][j]);		
			i++;
			}
		printf("\nEter Test CAse:");	
		scanf("%s",s);	
		i=0;
		while(i<4)
			{
				
				
				match(&a[i][j],s);
						
				i++;	
				
				
			}
		
	
	
	
	
	
	}

