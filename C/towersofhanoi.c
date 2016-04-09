//towers of Honoi

#include<stdio.h>
void TH(int n, char , char, char);
int main()
	{
	int n;
	char f='F',t='T',a='A';
	scanf("%d",&n);
	TH(n, f, t, a);
	return 0;
	}

void TH(int n, char FROM, char TO, char AUX) 
 {
	if (n==1)
		{
			printf("Move [%d] from |%c| to |%c|\n\n", n, FROM, TO);
			return;
		}
		
	TH(n-1, FROM, AUX, TO);
	printf("Move [%d] from |%c| to |%c|\n\n", n, FROM, TO);
	TH(n-1, AUX, TO, FROM);
	
 
 }	