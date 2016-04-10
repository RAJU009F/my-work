#include<stdio.h>
#define int int*
int main(){
    int *p,q;
p=(int *)5;
q=10;
printf("%d",q+p);
return 0;
}
