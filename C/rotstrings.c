#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int isRotation(char *str1, char *str2)
{
	int s1=strlen(str1);
	int s2=strlen(str2);
	char *temp = (char *)malloc(sizeof(2*s1+1));

	if(s1!=s2)
			return 0;
	temp[0] = '\0';
	strcat(temp,str1);
	strcat(temp,str1);
	printf("%s,   %s\n\n",str2,temp);
if(strstr(temp,str2))
		return 1;
	
else
		return 0;
	
}


int main()
	{
	char *str1="ABCD";
	char *str2="BCDA";
	
	isRotation(str1, str2)==1?printf("true"):printf("not");
	
	
	
	}