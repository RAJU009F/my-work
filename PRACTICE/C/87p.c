#include<stdio.h>
#include<string.h>
union U
    {
        char name[100];
        int age;
        int mobile;
        float weight;
    
    
    };
    
 main()
    {
    
    union U x;
    strcpy(x.name,"NAX");
    x.age=22;
    x.mobile=963383;
    x.weight=45.7;
    printf("\n Deails:\n \tName:%s\n\t%d\n\t%d\n\t%f\n",x.name,x.age,x.mobile,x.weight);
    
    }   
