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
# Problem Statement	: max profit from share price
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class Intervel
{
	int buy;
	int sell;
}

public class MaxProfit
{

	public static void findProfitIndices(int arr[], int n)
	{
		int count = 0;
		ArrayList<Intervel> sol =  new ArrayList<Intervel>();
		for(int i=0; i<n; )
		{
			while(i<n-1 && arr[i]>=arr[i+1])
				i++;
			if(i == n-1)
				break;
			Intervel e =  new Intervel();
			e.buy = i++;
			while(i<n && arr[i]>=arr[i-1])
				i++;
			e.sell = i-1;
			
			sol.add(e);
			count++;
			
			
		}
		
		if(count==0)
			System.out.println(" There is no profitable intervel found");
		else
			for(int i=0; i<count; i++)
				System.out.println("buy:"+sol.get(i).buy+" sell: "+sol.get(i).sell);
			
		
	}

	public static void main(String args[])
	{
	
		int arr[] = {100, 180, 260, 310, 40, 535, 695};
		
		findProfitIndices(arr, arr.length);
	
	
	}

}