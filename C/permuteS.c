#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void permute(char *, int, int);
void swap(char *, char *);

int main()
	{
	char s[] = "ABC";
	int size = strlen(s);
	permute(s,0,size-1);
	return 0;
	}
void swap(char *a, char *b)
		{
			
			char temp;
			temp =*a;
			*a = *b;
			*b =temp;
			
			//*a)= *a^*b;
			//*b= *a^*b;
			//*a= *a^*b;
		
		
		}
void permute(char *str, int l, int r)
		{
		int i;
		if(l==r)
			{
				printf("\t[%s]",str);
			}
		else{for(i=l;i<=r;i++)
			{
			swap(str+l,str+i);
			permute(str,l+1,r);
			swap(str+l,str+i);
			}
		}
		
		}