#include<stdio.h>

#include<stdlib.h>
#include<string.h>
void process(int *lps,char *p,int m)
	{
		int i=0;
		lps[0]=0;
		i=1;
		int len=0;
		while(i<m)
		{
			if(p[len]==p[i])
				{
					len++;
					lps[i]=len;
					i++;
				
				
				}
				
			else
			{
				if(len)
					{
						len=lps[len-1];
					}
				else
					{
						lps[i]=0;
						i++;
					
					}
			
			
			}	
		
		}
	
	
	
	}
void kmpsearch(char *t,char *p)
	{
		int m=strlen(p);
		int n=strlen(t);
		
		int *lps=(int *)malloc(sizeof(int)*m);
		process(lps,p,m);
		int i=0,j=0;
		while(i<n)
			{
				if(p[j]==t[i])
					{
						i++;
						j++;
					
					}
				if(j==m)
					{
						printf("pattern occured at:%d\n\n",i-m);
						j=lps[j-1];
					
					}	
					
			else if(p[j]!=t[i])
				{
					if(j)
						j=lps[j-1];
					else
						i++;	
				
				
				
				}		
			
			
			}
	
	
	}




main()
	{
		char *t="naxananananananax";
		char *p="nax";
		kmpsearch(t,p);
	
	
	}
