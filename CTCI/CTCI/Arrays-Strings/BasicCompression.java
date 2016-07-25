import java.io.*;
import java.lang.*;
import java.util.*;

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: CTCI
# Problem Statement	: insert %20 instead of spaces in a string
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

public class BasicCompression
{
	public static void main(String args[])
	{
		char[] str = "AAAAABBBBCCCDDDEEEK".toCharArray();
		System.out.println(compressString(str));
		char[] str1 = "ABCDEFG".toCharArray();
		
		System.out.println(compressString(str1));
		
		
		
	}
	
	
	public static boolean isCompressable(char str[])
	{
		char last = str[0];
		int count =1;
		int size =0;
		for(int i=1; i<str.length; i++)
		{
			if(str[i] == last)
			{
				count++;
			}else
			{
				last = str[i];
				size += 1+String.valueOf(count).length();
				count = 1;
				
			}
			
			
		}
		
		size += 1+String.valueOf(count).length();
		
		return size>str.length;
		
	}
	
	public static String compressString(char str[])
	{
		if(!isCompressable(str))
			return str.toString();
		
		char last = str[0];
		int count = 1;
		int size = 0;
		int index = 0;
		for(int i=1; i<str.length; i++)
		{
			if(last == str[i])
			{
				count++;
			}else
			{
				if(count==1)
				{str[index] =(char) last;
				index++;}else
				{
					str[index] = (char)last;
					index++;
					for(int j=String.valueOf(count).length()-1; j>=0; j--)
					{
						str[index] = (char)(String.valueOf(count).charAt(j));
						index++;
					}
					
					
				}
				
			}
			
		}
		
		if(count==1)
				{str[index] = last;
				index++;}else
				{
					str[index] = last;
					index++;
					for(int j=String.valueOf(count).length()-1; j>=0; j--)
					{
						str[index] = String.valueOf(count).charAt(j);
						index++;
					}
				}
		
		return str.toString();
	}
	
	
	
	
	
	
	}	
	