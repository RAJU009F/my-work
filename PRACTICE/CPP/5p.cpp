#include<iostream>

using namespace std;

int main()
        {
        int i,j;
        const int n=5;
        for(i=0;i<=2*n;i++)
                {
                        for(j=0;j<=2*n;j++)
                        {
                                if(i<=n)
                                        if(n-i>j||n+i<j)

                                                cout<<" ";
                                        else
                                        cout<<  "*";
                                else
                                        if(j<i-n||j>3*n-i)
                                                cout<<" ";
                                        else
                                                cout<<"*";              
                                                                        
                                
        
                        }
                        cout<<"\n";
                        
                }
                        
        
        
        }

