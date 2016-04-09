// permute String

#include<stdio.h>
#include<string.h>
void permute(char *, int, int);
void swap(char *, char *);
void swap(char *a, char *b)
{
	char temp;
	temp =*a;
	*a = *b;
	*b= temp;
	
	
}
void permute(char *a, int l, int n)
{
	int i;
	if(l==n)
	{
		
		printf("\t[%s]",a);
		return;
		
	}
	else
	{
		for(i=l;i<=n;i++)
		{
			
			swap((a+l), (a+i));
			permute(a,l+1,n);
			swap((a+l),(a+i));
			
		}
		
	}
	
	
	
}

int main()
{

char s[] = "ABC";
int n = strlen(s);
permute(s,0,n-1);
return 0;

}

