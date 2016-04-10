/*RUN LENGTH ENCODING*/
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

char *encode(char *str)
    {
        int i;
        int len=strlen(str);
        char count[50];
        
         char *dest = (char *)malloc(sizeof(char)*(len*2 + 1));
        int j=0,k;
        for(i=0;i<len;i++)
            {
                dest[j++]=str[i];
                
                int cnt=1;
                while(i+1<len && str[i]==str[i+1])
                    {
                        cnt++;
                        i++;
                    }
                sprintf(count,"%d",cnt);
                for(k=0;*(count+k);k++,j++)               
                {
                  dest[j]=count[k];    
                }
            
            
            }
            dest[j]='\0';
            
         return dest;   
        
    
    
    }








main()
    {
        char s[]="geeksforgeeks";
        
        char *res=encode(s);
        printf("%s\n\n",res);
    
    
    
    
    }
