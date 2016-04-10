#include<stdio.h>
#include<stdlib.h>
#define s(t) (int )(&t+1)-(int )(&t)
int sum(int a,int b)
    {
        return printf("%*c%*c",a,'\r',b,'\r');
    
    }
int add(int m,int n)
    {
        char *c=(char *)m;
        return &c[n];
    
    }    

int log(int n)
    {
    return (n>1)?1+log(n/2):0;
    
    }
    
int dsum(int n)
    {
    
        return n?(n%10)+dsum(n/10):0;
    }    

main()
    {
    int x;
    printf("add:%d\t\n",sum(3,4));
    
    printf("\nsum:%d\t\n",add(3,4));
    
    printf("log:%d\t\n",log(10));
    
    printf("digit sum:%d\n",dsum(2345));
    
    printf("size:%d\n",s(x));
    
    }
