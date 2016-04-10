#include<stdio.h>
#include<stdlib.h>

main()
	{
		char str[]="ABCCBCA";
		int len=strlen(str);
		int i,j=0;
		for(i=1;i<=len;i++)
			{
				while(str[i]==str[j] && j>=0)
					{
					i++;
					j--;
					}
				str[++j]=str[i];	
			
			
			}
			
		printf("%s\n",str);	
	
	
	
	}
