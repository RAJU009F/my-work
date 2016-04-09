#include<stdio.h>
#include<stdlib.h>

// Compress the String 
int countDigits(int num)
{
	int count =0;
	while(num)	
	{
		count++;
		num=num/10;
		
	}
	
	return count;
}
void compressString(char str[])
{
		int count=1;
		int in=0;
		int res_in =0;
	
		while(*(str+in))
		{
				char temp = *(str+in);
				if(*(str+in) == *(str+in+1))
						count++;
				else
				{
					
					*(str+ res_in)=temp;
					if(count>1)
					{
							int digits = countDigits(count);
							
							while(digits)
							{
							printf("%d\n",digits);
							res_in++;
								*(str + res_in + digits-1) =  (count%10) +48 ;
								count = count/10;
								digits--;
								
							}
						
						
					}
					
					res_in++;
					
					count =1;
				}
			
			in++;
			
			
		}
	
	*(str+res_in) = '\0';
	
	
	
}

int main()
	{
	char str[] = "AABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBCPPPPGGGH";
	compressString(str);
	printf("%s",str);
	
	return 0;
	}

