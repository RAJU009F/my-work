   /*      STAR SHAPE PRINTING     */
        
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
                                if(i==j)
                                        cout<<  "*";

                                                
                                else if(2*n-i==j)
                                        
                                        cout<<  "*";
                                        
                                else
                                        
                                                cout<<" ";
                                                
                                                                        
                                
        
                        }
                        cout<<"\n";
                        
                }
        
        
        
        }

