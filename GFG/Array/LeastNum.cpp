// import java.io.*;
// import java.lang.*;
// import java.util.*;

// #!/usr/bin/python -O

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include<stdbool.h>
// #include<limits.h>

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/ARRAY
# Problem Statement	: 
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void printLaest(string arr)
{
	
	vector<int> v;
	int min_avail =0;
	int pos_of_I = 1;
	
	if(arr[0]=='I')
	{
		v.push_back(1);
		v.push_back(2);
		min_avail = 3;
		pos_of_I = 1;
	}else
	{
		v.push_back(2);
		v.push_back(1);
		min_avail = 3;
		pos_of_I = 0;
	}
	
	for(int i=1; i<arr.length(); i++)
	{
		if(arr[i]=='I')
		{
			v.push_back(min_avail);
			min_avail++;
			pos_of_I = i+1;
			
		}else
		{
			v.push_back(v[i]);
			for(int j=pos_of_I; j<=i; j++)
				v[j]++;
			min_avail++;
			
		}
		
		
	}
	
	for(int i=0; i<v.size(); i++)
		cout<< v[i]<<" ";
	cout<<endl;
	
}


int main()
{

printLaest("DDDD");
printLaest("IDDI");
printLaest("DIID");

return 0;
}
