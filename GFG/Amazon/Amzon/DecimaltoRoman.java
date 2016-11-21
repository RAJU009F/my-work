// import java.lang.*;
// import java.util.*;
// import java.io.*;

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
#include<queue>
using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Graphs
# Problem Statement	: 
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------


#sample output
------------
*/


class GfG
{
    void convertToRoman(int n)
    {
	// 1 -I
    // 4 - IV
    // 5 - V
    // 9 - IX
    // 10 - X
    // 40 - XL
    // 50 -  L
    // 90 - XC
    // 100 - C
    // 400 - CD
    // 500 - D
    // 900 - CM
    // 1000 - M
    String res = "";
    
    int t;
    
    t =  n/1000;
    
    for(int  i=1; i<=t; i++)
        res +="M";
    n= n %1000;
    
    t =  n/900;
    for(int i=1; i<=t; i++)
        res += "CM";
        
    n = n%900 ;
    t =  n/500;
    for(int i=1; i<=t; i++)
        res += "D";
        
    n = n%500 ; 
    t = n/400;
    for(int i=1; i<=t; i++)
        res += "CD";
        
    n = n%400; 
    t = n /100;
    for(int i=1; i<=t; i++)
        res += "C";
        
    n = n%100 ;
    t = n / 90;
    for(int i=1; i<=t; i++)
        res += "XC";
        
    n = n%90 ;
    t = n/50;
    for(int i=1; i<=t; i++)
        res += "L";
        
    n = n%50 ;
    
    t = n/40;
    for(int i=1; i<=t; i++)
        res += "XL";
        
    n = n%40 ; 
    
    t = n/10;
    
    for(int i=1; i<=t; i++)
        res += "X";
        
    n = n%10;
    
     t = n/9;
    
    for(int i=1; i<=t; i++)
        res += "IX";
    n = n%9;    
    t = n /5;
    for(int i=1; i<=t; i++)
        res += "V";
        
    n = n%5 ;
    
    t = n/4;
    for(int i=1; i<=t; i++)
        res += "IV";
        
    n = n%4 ;
    
    t = n/1;
    
        for(int i=1; i<=t; i++)
            res += "I";
        
    n = n%1; 
    
    System.out.println(res);	
    }
}