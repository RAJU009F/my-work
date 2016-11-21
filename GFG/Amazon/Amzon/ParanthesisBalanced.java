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
# Problem Statement	: paranthesis validation
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class GFG {
    
    public static boolean isBalanced(char str[])
        {
            
            int i=0;
            
            int f  = 0;
            int o = 0;
            int b = 0;
            while(i<str.length)
                {
                    char t = str[i];
                    if((t == ']' && b == 0) || (t == ')' && o == 0)|| (t == '}' && f == 0) )
                        return false;
                    else if(t=='}')
                            f--;
                    else if(t==']')
                            b--;
                    else if(t==')')
                        o--;
                    else if(t=='(')
                        o++;
                    else if(t=='{')
                        f++;
                    else
                        b++;
                   i++; 
                    
                }
            return f==0&&b==0&&o==0;
            
            
        }
    
	public static void main (String[] args) {
            
            Scanner sc =  new Scanner(System.in);
            int T =  sc.nextInt();
            
            while(T-->0)
                {
                    String str  =  sc.next();
                    
                    if(isBalanced(str.toCharArray()))
                        System.out.println("balanced");
                    else
                        System.out.println("not balanced");
                    
                    
                }
            
	}
}