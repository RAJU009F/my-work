#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void findlargest(char *str)
	{
		int i,j,len=strlen(str);
		int low,high,maxl=0,start=0;
		for(i=0;i<len;i++)
			{
			
				low=i-1;high=i;
				while(low>=0&&high<len&&str[low]==str[high])
					{
						if(high-low+1>maxl)
							{
								start=low;
								maxl=high-low+1;
							
							}
							
							
					
					--low;
					++high;
					
					
					}
					
					low=i-1;high=i+1;
				while(low>=0 && high<len && str[low]==str[high])
					{
						if(high-low+1>maxl)
							{
								start=low;
								maxl=high-low+1;
							
							
							}
						--low;
						++high;	
					
					
					
					
					}
			
			
			
			
			}
			
			printf("%d\n\n",maxl);
			for(i=start;i<start+maxl;i++)
				{
					printf("%c",str[i]);
					
				
				
				}
				printf("\n\n");
	
	
	
	
	}


main()
	{
	
		char str[]="naxliteislivinginmalayalam";
		
		findlargest(str);
	
	
	
	
	}
