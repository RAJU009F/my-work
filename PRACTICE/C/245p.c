#include<stdio.h>
#include<stdlib.h>
int poss()
	{
		int a,b,c,cnt=0;
	
		for(a=75;a>=25;a--)
			{
				for(b=50;b>=0;b--)
					{
						for(c=25;c>=0;c--)
							{
								if(a+b+c==100)
									cnt++;
							
							
							}
					
					
					}
			
			
			}
	
	
	
		return cnt;
	
	}

main()
	{
	
		printf("possibilities::%d\n\n",poss());
	
	
	}
