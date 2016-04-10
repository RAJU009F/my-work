#include<stdio.h>
#include<stdlib.h>
int x=0;

int f1()
    {
        x=5;
        return x;
    
    
    }
    
int f2()
    {
        x=10;
        return x;
    
    }    
main()
    {   
        char str[535];
        scanf("%[^\n]s",str);
        printf("%sffh%fhf\n\n",str);
        
        fputs("na%xlite",stdout);
        fputs("gee%n5%ks",stdout);
        int c;
        printf("\n\nnaxlite%nindian",&c);
        printf("%d",c);
    int p=f1()+f2();
    
    printf("\n\n\\n\n\n\n%d",x);
    
    int x = 10, y;
  
    // The following is equavalent to y = x++
    y = (x++, printf("x = %d\n", x), ++x, printf("x = %d\n", x), x++);
  
    // Note that last expression is evaluated
    // but side effect is not updated to y
    printf("y = %d\n", y);
    printf("x = %d\n", x);
    
    
    int i=10;
   
    int s=sizeof(++i);
    printf("size:%d\tva:%d\n\n\n",s,(++i));
  
    }
