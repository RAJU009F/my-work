#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define D "."
int is_digit(char *str)
    
    {   int i=0;
        while(*(str+i))
            {
                if(str[i]>='0' && str[i]<='9')
                       i++;
                 else
                    return 0;      
            }        
    
        return 1;
    }

int myatoi(char *str)
    {
       int sign=1,res=0;
       int i=0;
       if(str[i]=='-')
        {
            sign*=-1;
            i++;
        }
          while(*(str+i)!='\0')
                {
                
                  res=10*res+str[i]-'0';
                  i++;
                }
           
       return sign*res;           
    
    
    }

int isvalid_ip(char *str)
    {
       
        int num,dot=0;
        if(str==NULL)
            return 0;
         char *s=strtok(str,D);
         if(s==NULL)
            return 0;    
        while(s)
            {
                if(!is_digit(s))
                       return 0;
                int num=myatoi(s);
                    printf("%d\t",num);
                
                if(!(num>=0 && num<=255))
                    return 0;
                        
                
                   
            
                    s=strtok(NULL,D);
                    if(s!=NULL)
                        ++dot;
            
            }
            
          if(dot!=3)
                return 0;
           return 1;      
                  
    
    
    
    }

main()
    {
        clock_t t;
        char ip[]="192.168.4.505";
        t=clock();
        if(isvalid_ip(ip))
            printf("Valid ip\n");
        else
            printf("not valid:\n");    
    
        //t=clock()-t;
        
        double time= ((double)t)/CLOCKS_PER_SEC;
        
        printf("Time:%f sec...\n\n",time);
    }
