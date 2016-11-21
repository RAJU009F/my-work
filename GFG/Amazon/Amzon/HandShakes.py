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
# Topic or Type 	: GFG/Amazon
# Problem Statement	:  HandShakes without crosses
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

T =  int(raw_input().strip())

while T>0:
    N =  int(raw_input().strip())
    N = N/2;
    num = 1
    
    for i in range(2*N, N+1, -1):
        num *= i
    d = 1    
    for i  in range(1, N+1):
        d *=i
    print(num/d)    
        
    
    
    
    T = T -1