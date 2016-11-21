import java.lang.*;
import java.util.*;
import java.io.*;

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
// #include<queue>
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Amazon
# Problem Statement	: Kth element in spiral print
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------


#sample output
------------
*/

class BomberAlgo
	{
		
		public String bomberAlgoImple(String input)
			{
				if(input == null)
					return null;
				char a[] = input.toCharArray();
				int n  	 = input.length();
				
				int i =0 ;
				int j = 0;
				while(j<n-1)
				{
					
					if(a[j] == a[j+1] )
							j = j+1;
					else if (i>0&&a[i-1] ==a[j])	
						{		i = i-1;
								j = j+1;
						}
					else
					{
						a[i] = a[j];
						i++;
						j++;
					}
					
					
				}
				a[i] = '\0';
				return a.toString();
			
			}
	
		public static void main(String args[])
			{
			
				BomberAlgo ba =  new BomberAlgo();
				String str  = "aabcccdee";
				System.out.println(ba.bomberAlgoImple(str));
			
			
			}
	
	}