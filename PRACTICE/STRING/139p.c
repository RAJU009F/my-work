#include<stdio.h>
#include<stdlib.h>

void printwords(char *list[],char *s,int wl)
    {
        int count[256]={0};
       int i=0;
       
        while(*(s+i))
            {
                count[*(s+i)]++;
                i++;
                
            
            }
          i=0;
          int j=0;
         
         for(j;j<wl;j++)
            {   i=0;
             int cnt=0;
                while(*(list[j]+i))
                    {
                        if(count[*(list[j]+i)])
                            {
                                cnt++;
                               count[*(list[j]+i)]=0;
                               
                               
                                
                             } 
                             
                         if(cnt==3)
                            {
                                printf("%s\n\n",list[j]);
                                break;
                            }      
                            i++;
                    
                    } 
                 i=0;   
             while(*(s+i))
            {
                count[*(s+i)]++;
                i++;
                
            
            }   
                    
                      
                
            } 
            
    
    }


main()
    {
    
    char *list[]={"urikdlksjdj","eresdsadd","naxalite","inindian","hitler"};
    char s[]="let";
    
    printwords(list,s,5);
    
    }
