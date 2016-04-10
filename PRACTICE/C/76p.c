#include<stdio.h>
#include<stdlib.h>
int main(){
int arr[]={0,10,20,30,40};
    char *ptr=arr;
    *(ptr++);
    printf("%d",*ptr);
    
    int a;
    int s=sizeof(a);
    printf("%d\n",s);
    
    return 0;        
}
