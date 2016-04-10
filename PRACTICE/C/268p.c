#include<stdio.h>

main()
	{
	
	
	extern int i;
	//i=0;
	printf("\n\n%d\n\n%d\n\n",sizeof(i),i);
	
	union a
		{
			int i;
			char ch[2];
			
		
		
		};
		union a z={512};
		printf("\n\n%d%d\n\n",z.ch[0],z.ch[1]);
		
		int ar[5]={1,2};
		printf("%d\t%d\t%d\n",ar[2],ar[3],ar[4]);
		
		
		enum st{p,f,a};
		enum st s1,s2,s3;
		s1=p;
		s2=f;
		s3=a;
		
		printf("\n%d \n%d \n%d\n",s1,s2,s3);
		
		
		char ch;
		if((ch=printf("")))
			printf("Naxalite:");
		else
			printf("No NAx");	
			
		switch(i)
		{}	
		
		static in A[34];
		int j=0;
		A[j]=j++;
		A[j]=8;
		
	
	}
	
	int i=20;
