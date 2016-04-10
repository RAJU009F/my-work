#include<stdio.h>
#include<stdlib.h>


main()
    {
    int h=20,i=10;
       printf("%d\n\n",h,i); 
       
       char str[]="raju";
       printf("size:%d\n\n",sizeof(str));
       char *ptr=str;
       
       while(*ptr!='\0')
        ++*ptr++;
        
      printf(" %s",str);  
    int c=15;
 printf("%d\n%d\n%d", c, c <<= 2, c >>= 2);
    
    }
