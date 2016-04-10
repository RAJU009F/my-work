#include<stdio.h>
#include<string.h>

#define D '\n'

void printlast(char *str,int n)
    {
        int cnt=0;
        char *target=NULL;
        target=strrchr(str,D);
    
        while(cnt<n)
            {
                while(str<target && *target!=D)
                    --target;
                 if(*target==D)
                    {
                    
                        --target,
                        ++cnt;
                    }       
                 else
                    break;   
            
            }
        if(str<target)
            target+=2;
    
    printf("%s\n\n",target);
    }

main()
    {
        char *str=" adjod jhdj kod ad]]gh\nnaxalite is the man to rule the world in next coming 10 years aftrr 10 years\nand he ll kill all andrsa idiots who are \naginst telangana and he wil \nthe man to\n ambassoder kpkkfkds\ndfsfs\njnaxalite chattisghar\ntheirnaxalite hello ooosdf sulvajudem ";
    
  
        printlast(str,10);
    
    }
