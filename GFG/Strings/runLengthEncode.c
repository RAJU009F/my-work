// import java.io.*;
// import java.lang.*;
// import java.util.*;

// #!/usr/bin/python -O

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<limits.h>

// #include<iostream>
// #include<algorithm>
// #include<string>
// #include<vector>
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Strings
# Problem Statement	: Run lenght encode
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void encode(char *str, int n)
{
	if(!*str)
		return;
	int count = 1;
	char last =  str[0];
	int i;
	int j=0;
	char temp[n];
	for(i=1; i<n; )
	{
		if( i<n &&last == str[i])
		{
			while(i<n && str[i]==last)
			{
				count++;
				i++;
			}
		}else
		{
			
			str[j] = last;
			j++;
			if(count>1)
			{
				sprintf(temp, "%d", count);
				int k=0;
				for(k=0;*(temp+k); k++, j++)
				{
					str[j] = *(temp+k);
				}
				
			}
			last = str[i];
			count =1;
			i++;
		}
		
		
	}
	

	str[j] = last;
			j++;
			if(count>1)
			{
				sprintf(temp, "%d", count);
				int k=0;
				for(k=0;*(temp+k); k++, j++)
				{
					str[j] = *(temp+k);
				}
				
			}
	
	str[j] = '\0';
	
	
}

int main()
{
	char str[] = "qqqqqfsssdsseeeedrrrr";
	printf("Before Encode:: %s\n",str);
	encode(str, strlen(str));
	printf("After Encode::%s\n",str);
	return 0;
}
