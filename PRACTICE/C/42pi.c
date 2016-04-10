#include<stdio.h>
#include<stdlib.h>

void f(char *x) {
	x++;
	*x = 'a';
}
int main() {
	char str[] = "hello";
	f(str);
	printf("%s", str);
}
/*main()
	{
	/*
	int x,i=2;
	x=~-!++i;
	printf("%d",x);
	printf("\n\n%d %d","NAX"-"NAX",sizeof 1);
	i=2;
	int a=i++ + ++i;
	printf("\n%d\n",i);
	int b=++i+ ++i + ++i;
		/*  sdsadsadprintf("\n\n%d %d\n",a,b);
		
		*
		
		
		int a[]={1,2,3,4};
		
		printf("%d\t\t%d\n\n","NAX",&"NAX");
		
		
		printf("%d\n\n",a[10]);
	
	}*/
