import java.io.*;
import java.util.*;
import java.lang.*;

/*

# Author			: @RAJ009F
# Topic or Type 	: Miscllanious
# Problem Statement	: Generate all valid parenthesis
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/

class ValidParenthis
{
	
	public static void printParenthis(char arr[], int st,  int cl, int pos, int N)
	{
		if(cl==N)
		{	System.out.println(arr);
			return;
			
		}else if(cl<st)
		{
		arr[pos] = '}';
		printParenthis(arr, st, cl+1, pos+1, N);
			
		}if(st<N)
		{
			arr[pos] = '{';
			printParenthis(arr, st+1, cl, pos+1, N);
			
		}
		
		
	}
	
	
	public static void main(String args[])
	{
		
		int N = 2;
		char[] arr =  new char[N*10];
		printParenthis(arr,0, 0, 0, N);
		
	}
	
}
