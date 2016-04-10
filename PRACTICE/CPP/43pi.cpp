#include<iostream>
#include<stdlib.h>

using namespace std;

char * ip(int num)
	{
		char b[37];
		sprintf(b,"%d.%d.%d.%d",(num>>24)&0xFF,(num>>16)&0xFF,(num>>8)&0xFF));
		return (char *)(b);
	
	}

int main()
	{
		cout<<ip(19216845);
	
	}
