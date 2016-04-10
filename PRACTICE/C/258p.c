#include<stdlib.h>
#include<stdio.h>

int p(int a,int b,int c)
	{
		return a+b+c;
	
	}
 float avg(float x,float y,float z){
    return (x+y+z)/3;
}	
	
main()
	{	int x=10,y=10,z=20;
		printf("%d",p(x,(z=100,y=0,x=100),z));
		 float p=1,q=2,r=-2,a;
    a=avg(p,(q=4,r=-12,q),r);
    printf("%f",a);
    int num,a1=10;
    num=++a1;
    printf("\n%d  %d",num,a1);
    const int a5=5;
     int b=a5;
    printf("%d %d",a5,b);
	
	
	}
