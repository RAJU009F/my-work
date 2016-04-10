#include<stdio.h>
#include<stdlib.h>
void divide(char *s,int n)
    {
        int len=strlen(s);
        if(len%n)
            {
                printf("not equal parts:%d\n",len);
                return;
            
            }
            int i=0;
            int ps=len/n;
          for(;i<len;i++)
            {
                if(!(i%ps))
                    printf("\n");
                printf("%c",s[i]);    
            
            }  
            
    printf("\n\n");
    
    
    }

main()
    {
        char s[]="naxliteis-the-man-to-rule-the-world";
        int n;
        printf("Enter the D:");
        scanf("%d",&n);
        
        divide(s,n);
    
    
    
    }
    
    
