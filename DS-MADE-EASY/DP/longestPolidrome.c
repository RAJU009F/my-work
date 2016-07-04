#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: DSME/DP
# Problem Statement	: longest polindrome
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/


void longestPolidrome(char *str)
{
	int long_start;
	int long_end;
	
	int start;
	int end;
	
	int mid;
	
	for(mid=0; mid<strlen(str); mid++)
	{
			// incase of odd
			start = mid;
			end = mid;
			
			while(start>=0 && end<strlen(str))
			{
				if(str[start] == str[end])
				{
					if(end-start> long_end-long_start)
					{
						long_end = end;
						long_start = start;
					}
					
					
				}else
					break;
				start--;
				end++;
				
			}
	
		
		
		// in case of even
		start = mid;
			end = mid+1;
			
			while(start>=0 && end<strlen(str))
			{
				if(str[start] == str[end])
				{
					if(end-start> long_end-long_start)
					{
						long_end = end;
						long_start = start;
					}
					
					
				}else
					break;
				start--;
				end++;
				
			}
	
		
	}
	
	//printf("Longest common substring::%s\n",substr(str, long_start, long_end) );
	int i= long_start;
	for(i; i<=long_end; i++)
		  printf("%c",str[i]);
	
	
}


int main()
{
	char *str="forgeeksskeegquiz";
	longestPolidrome(str);
	

return 0;	
}
