#include<iostream>
 #include<string.h>
 
 using namespace std;
 void rev();
 
 int main()
    {
    
    
    rev();
    
    
    
    }   
    
    
void rev()
    {
    
    char c;
   // cin.get(c);
   cin>>c;
    if(c=='\n')
        return;
     rev();
     cout<<c;  
    
    
    
    }    
