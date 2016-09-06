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
# Problem Statement	: largest number possible
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

int myCompare(string x, string y)
{
	string xy = x.append(y);
	string yx = y.append(x);
	
	return xy.compare(yx)>0?1:0;
	
}

void printLargestNum(vector<string> vec)
{
	sort(vec.begin(), vec.end(), myCompare);
	
	for(int i=0; i<vec.size(); i++)
		cout<<vec[i];
	
}

int main()
{
	
	vector<string> arr;
	arr.push_back("54");
    arr.push_back("546");
    arr.push_back("548");
    arr.push_back("60");
	printLargestNum(arr);
	return 0;
}