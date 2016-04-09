// Rand7( 0 to 6) and rand7(1...7) using rand5

//II - method 5x5 grid method

#include<stdio.h>
#include<stdlib.h>

int rand7();
int rand5();
int rand2();

int rand1_7();
int rand1_5();
int rand1_2();
int rand7_5x5();
	
int  main()
	{
	
	
	int x=7, i,y;
	scanf("%d",&x);
	for(i=0; i<x; i++)
		{
			y= rand7();
			printf("\t%d\n", y);
			
		}
		printf("\t===========\n");
	for(i=0; i<x; i++)
		{
		y= rand1_7();
		printf("\t%d\n", y);
		}
		printf("\t===5x5 =======\n");
	for( i =0; i<x; i++)
	{
		y= rand7_5x5();
		
		printf("\t%d\n",y);
		}
 return 0;
	
	
	}
	
int rand7_5x5(){
	int x = 5*rand5() + rand5();
	if (x>20)
		{
			return rand7_5x5();
		}
	else
		{
			return x%8;
		}


}
	
int rand1_5()
		{
			return rand()%5+1;
		}
int rand1_2()
			{
			int x = rand1_5();
			if ( x==5)
			{	return rand1_2();}
			else{
				return x%2;
			}
			
			}
		
	
int rand1_7()
		{
			int x = rand1_2()*4 + rand1_2()*2 + rand1_2();
			if ( x==0)
			{
				return rand1_7();
			}else
			{
				return x;
			}
		}
	
	
int rand2()
	{
		int x = rand5();
		if ( x == 4)
			{
			return rand2();
			}
		else{
			return x%2;
		}	
	
	}
int rand7()
	{
		int x = rand2()*4 + rand2()*2 + rand2();
		if (x == 7)
			{
				return rand7();
			}
		else
			{
			return x;
			}

		}

int rand5()	
	{
	
	return rand()%5;
	
	}	
	