#include<stdio.h>
#include<stdlib.h>

typedef unsigned char *byte;
void showb(byte s,int len)
	{
		int i;
		for(i=0;i<1;i++)
			printf("%.2x",s[i]);
	}

void show(int x)

	{
		showb((byte)&x, sizeof(int));
	
	
	}



main()
	{
	int i;
	int *p=&i;
	
	float T=232.677;
	char ret[34];
	sprintf(ret,"%f",T);
	printf("%s\n",ret);
	show(i);
	
	}
