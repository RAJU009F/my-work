#include<stdio.h>

int cnt(int);
main()
    {
        long *p;
        int *q;
        char *p1;
        printf("%d\t%d\t%d \n\n",sizeof(*p),sizeof(*q),sizeof(*p1));
    
        int r=cnt(100);
        printf("%d\n",r);
    
    }
    
int cnt(int n)
    {
    
      if(n<=1)
        return n;
      else
        return n-(n%2)?cnt(n-3):cnt(n/2);
        
    
    
    
    }    
