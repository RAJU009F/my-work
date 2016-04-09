// Drop Egg

#include<stdio.h>
#include<stdlib.h>
int dropEgg(int F, int E);
int min(int , int);
int max(int, int);
int main()
	{
	int F,E;
	scanf("%d",&F);
	scanf("%d",&E);
	printf(" Max Floor: %d \n",dropEgg(F, E));
	return 0;
	
	
	}
	
int min(int a, int b)
{
	return a<b?a:b;
	
}
int max(int a, int b){
	
	return a>b?a:b;
}
	
int dropEgg(int F,  int E)
{
	int m=1000,x,r;
	if(F==0||F==1)
		return F;
	if(E==1)
		return F;
	for(x=1; x<=F; x++)
	{
		r = max(dropEgg(F-x, E), dropEgg(x-1, E-1));
		if(r<m)
			m =r;
	}
return 1+m;
	
	
	
}