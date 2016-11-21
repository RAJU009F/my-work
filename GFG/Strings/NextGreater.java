
import java.io.*;
import java.lang.*;
import java.util.*;

// #!/usr/bin/python -O

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include<stdbool.h>
// #include<limits.h>

// #include<iostream>
// #include<algorithm>
// #include<string>
// #include<vector>
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/ARRAY
# Problem Statement	: lexicographically next string
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/



class NextGreater
{
	public static void  printNextString(String str)
	{
			int len = str.length();
			char[] ch = str.toCharArray();
			int i=len-1;
			
			while(i>0 && ch[i]>=ch[i-1])
				i--;
			if(i<=0)
			{
				System.out.println("no string possible");
				return;
				
			}
			
			int pivot = -1;
			for(int j=i; j<len; j++)
			{
				System.out.println(ch[i-1]+" "+ch[j]);
				if(ch[i-1]<ch[j]&&pivot==-1)
				{
					pivot=j;
				}
				
				if(ch[i-1]<ch[j]&&pivot!=-1&&ch[pivot]>ch[j])
						pivot = j;
					
				
			}
			
			// char c = ch[pivot];
			// ch[pivot] = ch[i-1];
			// ch[i-1] = c;
			
			// Character[] temp =  new Character[len-i+1];
			// for(int j=i; j<len; j++)
				// temp[i-j] = ch[j];
		
			// Arrays.sort(temp );
			// for(int j=0; j<temp.length; j++)
					// ch[i+j] = temp[j];
			
		System.out.println(ch.toString());
		
	}
	public static void main(String args[])
	{
	
	String str = "hdfc";
	printNextString(str);
	}

}