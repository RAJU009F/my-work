import java.io.*;
import java.lang.*;
import java.util.*;
/*
#!/usr/bin/python -O

# // #include <stdio.h>
# // #include <stdlib.h>
# // #include <string.h>
# // #include<stdbool.h>
# // #include<limits.h>

# // #include<iostream>
# // #include<algorithm>
# // #include<string>
# // #include<vector>
# // using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Arrays
# Problem Statement	: compare Versions and get the latest one 
# Description		: 
# Complexity		: 
# =======================
# sample output
# ----------------------

# =======================
*/ 


class CompareVersions
{
	public static int  getLatestVersion(String version1, String version2)
	{
		String[]  v1 = version1.split("\\.");
			
		String[]  v2 =  version2.split("\\.");
		
		int min_len  =  Math.min(v1.length, v2.length);
		
		for(int i=0; i<min_len; i++)
		{	
			int tokenv1 =Integer.parseInt(v1[i]);
			int tokenv2 = Integer.parseInt(v2[i]);
			//System.out.println(tokenv1+tokenv2);
			if(tokenv1> tokenv2)
			{	return 1;}
			else if(tokenv2>tokenv1)
			{return 2;}
			else
					continue;
			
		}
		
	if (v1.length> v2.length)
			return 1;
	else if ((v1.length< v2.length))
			return 2;
	else
			return 3;
		
	}
	
	
	public static void main(String args[])
	{
		String version1 = "1.11.2";
		String version2 = "1.102.1";
		int res = getLatestVersion(version1, version2);
		if(res ==1)
				System.out.println(version1);
		else if (res==2)
				System.out.println(version2);
		else
				System.out.println("Both represents same release");
		 version1 = "1.102.1";
		 version2 = "1.102.1";
		res = getLatestVersion(version1, version2);
		if(res ==1)
				System.out.println(version1);
		else if (res==2)
				System.out.println(version2);
		else
				System.out.println("Both represents same release");
		
		
	}
	
}
