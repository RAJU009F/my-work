#include<stdio.h>
#include<stdlib.h>
void print(char *str,int l,int h)
    {
        printf("logest polin:\n\n");
        int i=l;
        for(i;i<=h;++i)
            printf("%c",str[i]);
            
       printf("\n\n");     
    
    
    }

void printpol(char *str)
    {
    
        int m=strlen(str);
        int start,max=1;
         int high;
         int low;
        int i=0;
        for(i=1;i<m;i++)    
            {
                low=i-1;
                high=i;
                
                while(low>=0 && high<m && str[low]==str[high])
                    {
                        if(high-low+1>max)
                            {
                                start=low;
                                max=high+1-low;
                            
                            }
                            
                            --low;
                            ++high;
                    
                    
                    } 
                    
                    low=i-1;
                    high=i+1;     
                while(low>=0 && high<m && str[low]==str[high] )
                    {
                    
                        if(high-low+1>max)
                            {
                                start=low;
                                max=high+1-low;
                            
                            
                            }
                            --low;
                            ++high;
                    
                    
                    }    
                  
                 
            
            
            
            
            }    
             print(str,start,start+max-1);  
                    
    
    
    }
    
    

main()
    {
        char str[]="indianmalayalam";
        
        printpol(str);
        
        
    
    
    }
