#include<stdio.h>
#include<stdlib.h>
 int longest(char *str) 
    {
        int *visited=(int *)malloc(sizeof(int)*256);
        int cur_len=1;
        int max_len=1;
        
        int i=0;
        for(i=0;i<256;i++)
            visited[i]=-1;
            int index;
         visited[str[0]]=0;
         for(i=0;i<strlen(str);i++)
            {
            
                index=visited[str[i]];
                if(index==-1||i-cur_len>index)
                    cur_len++;
                else
                    {
                        if(cur_len>max_len)
                            max_len=cur_len;
                        cur_len=i-index;
                        
                    }    
                visited[str[i]]=i;
            
            }  
                if(cur_len>max_len)
                    max_len=cur_len;
        free(visited);
        
        return max_len;
    }
    int longest1(char *str)
    {
        int m=strlen(str);
        int visited[256];
        int i;
        for(i=0;i<256;i++)
            visited[i]=-1;
            i=0;
        visited[str[i]]=0;
        int index,cur_len=1,max_len=1;
        for(i=1;i<m;i++)
            {
                index=visited[str[i]];
                if(index==-1 || i-cur_len>index)
                    cur_len++;
               else
               {     
                if(max_len<cur_len)
                    max_len=cur_len;
                    
                    cur_len=i-index;    
                }
               visited[str[i]]=i; 
            }    
            
        if(cur_len>max_len)
            max_len=cur_len;
            
        return max_len;    
    
    
    
    }

    
main()
    {
        char str[]="geeksforgeeks";
        printf("longest unique substring:%d\n\n",longest1(str));
    
    
    
    }
    
   
