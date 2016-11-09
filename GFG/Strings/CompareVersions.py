# import java.io.*;
# import java.lang.*;
# import java.util.*;

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

# /*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Arrays
# Problem Statement	: Compare Vesrions and return latest version
# Description		: 
# Complexity		: 
# =======================
# sample output
# ----------------------

# =======================
# */ 

def compare(version1, version2):
	version1L = version1.split(".")
	version2L = version2.split(".")
	
	max_len = min(len(version1L), len(version2L))
	for i in range(0, max_len):
		if int(float(version1L[i])) > int(float(version2L[i])):
			return 1
		elif int(float(version1L[i])) < int(float(version2L[i])):
			return 2
		else:
			continue
			
	if len(version1L) > len(version2L):
		return 1
	elif len(version1L) < len(version2L):
		return 2
	else:
		return 3
 

def main():
	v1, v2 = ("1.11.2", "1.102.1")
	res = compare(v1, v2)
	if res == 1:
		print (v1)
	elif res ==2:
		print (v2)
	else:
		print ("both are same release")
	v1, v2 = ("1.102.1", "1.102.1")
	res = compare(v1, v2)
	if res == 1:
		print (v1)
	elif res ==2:
		print (v2)
	else:
		print ("both are same release")	
		
	# compare("1.11.2", "1.102.1")
	# compare("1.11.2", "1.102.1")

if __name__=="__main__":
	main()