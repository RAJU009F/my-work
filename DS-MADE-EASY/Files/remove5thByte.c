#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Geenral question
# Problem Statement	: remove every 5th byte from the file.
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/


int main()
	{
		FILE *read_file, *write_file;
		int counter=1, i=0;
		char ch;
		
		read_file = fopen("input_file.txt","r");
		write_file = fopen("input_file.txt","r+");
		
		if(!read_file || !write_file )
		{
			printf("File not present\n");
			exit(1);
		}
		fseek(read_file, 0, SEEK_END);
		int size = ftell(read_file);
		printf("Size = %d\n",size);
		fseek(read_file, 0, SEEK_SET);
		while(counter < size)
		{
			ch = fgetc(read_file);
			if(counter%5 !=0)
				fputc(ch,write_file);
			else
				i++;
			counter++;
			
		}
		fclose(read_file);
		fclose(write_file);
		printf("Truncate by %d bytes",i);
	return 0;
	}