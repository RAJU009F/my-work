#include<stdio.h>
#include<stdlib.h>


int get();

main()
	{
	
		const int x=get();
		printf("%d\n\n\n",x);
		int i=1;
	  switch(i)
    {
        printf("Hello\n");
        case 1:
            printf("Hi\n");
            break;
        case 2:
            printf("\nBye\n");
            break;
    }
    return 0;
}
	
int get()
	{
	
		return 20;
	
	}		
