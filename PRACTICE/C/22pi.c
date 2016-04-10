#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void erote(int a[],int d,int N)
	{
		int i;
		if(d==2)
			i=2;
		else
			i=d+1;	
		for(;i<N;++i)
			{
				//printf("%d \t",a[i]);
				if(a[i] && (a[i]%d==0))
					a[i]=0;
			
			
			}
	
	
	}

main()
	{
		int N;
		printf("Enter limit::");
		scanf("%d",&N);
		int a[N];
		int i,j;
		int temp=0;
		for(i=2;i<N;i++)
			{
				a[temp++]=i;
				
			
			
			}
			
		for(i=2;i<sqrt(N);)
			{
				erote(a,i,N);
				if(i==2)
					i=i+1;
				else
					i=i+2;	
			
			}	
			int cnt=0;
		for(i=0;i<N;i++)
			{
				if(a[i])				
					printf("%d\t",a[i]);
				if(cnt%100==0)
					printf("\n\n\n");	
			
			
				cnt++;
			}	
		
		
	char *s="naxlite";
		printf("\n\n\n%c\n\n\n\n%s\n\n",*s++,s);
	
	
	}
