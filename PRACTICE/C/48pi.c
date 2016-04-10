#include<stdio.h>
#define add(a,b) a+b
#define mul(a,b) a*b
int main()
{
int a=10,b=20,c=30,d;

d=mul(c,add(a,b));
printf("%d \t\t%d",d,-102>>2);
return 0;
}
