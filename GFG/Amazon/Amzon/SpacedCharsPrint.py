# import java.io.*;
# import java.lang.*;
# import java.util.*;

 #!/usr/bin/python -O

'''// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include<stdbool.h>
// #include<limits.h>

// #include<iostream>
// #include<algorithm>
// #include<string>
// #include<vector>
// using namespace std;'''

# /*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Amazon
# Problem Statement	: spaced chars in string
# Description		: 
# Complexity		: 
# =======================
#sample output
# ----------------------

# =======================
# */

def toString(lst):
	s = ""
	for x in lst:
		if x  == '\0':
			break
		s += x
	return s
	
def printSpacedChars(s, d, i, n ,j):
	if i==n:
		d[j] = '\0'

		print (toString(d))
		return
	d[j] = s[i]
	printSpacedChars(s,d, i+1, n, j+1)
	d[j] = ' '
	d[j+1] = s[i] 
	printSpacedChars(s,d, i+1, n, j+2)
	

def main():
	N = int(input().strip())
	while N > 0:
		s =  input().strip()
		s = list(s)
		n = len(s)
		d = [0]*(2*n) 
		d[0] = s[0]
		printSpacedChars(s,  d, 1, n, 1);
		print ('\n')
		N = N - 1
main()		