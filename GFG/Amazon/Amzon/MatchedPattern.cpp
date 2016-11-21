// import java.lang.*;
// import java.util.*;

// #!/usr/bin/python -O

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<limits.h>

// #include<iostream>
// #include<algorithm>
// #include<string>
// #include<vector>
//using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Amazon
# Problem Statement	: print all the matched patttern string in the dictionary
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------


#sample output
----------------------

=======================
*/

/* The function returns a  vector of strings 
present in the dictionary which matches
the string pattern.
You are required to complete this method */
int gethash(string pattern)
{
    
    map<char, int> hash; 
    int i=0;
    int hashV = 0;
    
    for(int j=0; j<pattern.length(); j++)
        {
            if(hash.find(pattern[j]) == hash.end())
                {   i++;
                   hash[pattern[j]] = i; 
                 
                   hashV = hashV*10+ i; 
                  
                }
                else
                 hashV = hashV*10 + i;
            
        }
    
    return hashV;
}

vector<string> findMatchedWords(vector<string> dict,
                      string pattern)
{
       
       int hash =  gethash(pattern);
      // cout << hash;
       vector<string > arr ;
      // cout<< pattern;
       for (int i=0; i<dict.size(); i++)
            {
                if(pattern.length()== dict[i].length() && hash == gethash(dict[i]))
                    arr.push_back(dict[i]);
                
                //cout<< dict[i];
            }
       
       return arr;
}