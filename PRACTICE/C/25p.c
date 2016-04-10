#include<stdio.h>
#include<stdlib.h>

void cv(int ,int);
void cr(int *,int *);
main()

    {
        int a=4,b=2;
        printf("values at initial :  [%d] and [%d] \n",a,b);
        
        cv(a,b);
        
        printf("\nvalues after: cv call: [%d] and [%d] \n",a,b);
        cr(&a,&b);
    
        printf("\nvalues after: cr call: [%d] and [%d] \n",a,b);
    
    }
    
void cr(int *x,int *y)
    {
        *x=*x^*y;
        *y=*x^*y;
        *x=*x^*y;
    
    
    
    
    } 
    
void cv(int x,int y)
    {
        x=x^y;
        y=x^y;
        x=x^y;
    
    
    
    
    } 
