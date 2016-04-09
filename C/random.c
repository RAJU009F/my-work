#include <stdlib.h>
#include <stdio.h>
int main()
{
    unsigned int a, b, c;
    a = rand();
    b = rand();
    c = a + b;
    if( c < a || c < b)
    {
        printf("correct");
    }
     else
    {
        printf("error");
    }
}