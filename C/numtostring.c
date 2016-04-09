// number to function
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define convert(x) #x
int main()
{
float n;
char s[10];
char *s2="";
int num;
printf("\n\tEnter num to:");
scanf("%f",&n);
scanf("%d",&num);
sprintf(s,"%d",num);
printf("%s, %d, %d, %d",s,num,sizeof(s),sizeof(num));
s2=convert(num);
printf("\n\n\t%s, %d",s2,num);
return 0;
}
