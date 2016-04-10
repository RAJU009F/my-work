#include<stdio.h>
#include<stdlib.h>
		
void fun();

	main()
		{
			int a[3][3][2]={{1,2,3,4,5,6},{11,12,13,14,15,16},{21,22,23,24,25,26}};
			
			printf("%d ,%d ,%d \n",*(*(*(a+0)+2)+1),*(*(*(a+2)+1)+1),*(a[1][1]+1));
		
			char p1[]="hello";
			char p2[]="hello";
			if(p1==p2)
				printf("NAX Eq:\n");
			
			printf("%s,%s",p1,p2);
			
			char str[16]="naxal";
			str[5+1]='r';
			printf("%s\n\n",str);
			
			//fun();
			
		
		
		/*/char *h[]={"xx","yy","tt","ppp"};
		char *h2[]={h+3,h+1,h+2,h};
		char ***h3=h2;
		printf("%s\n\n",h3);*/
		
		int (*rra[2])(float,int,int)={NULL};
		
		union A
			{
				long int y[6];
				union B
					{
						double g;
						union C
							{
								int k;
								union D
									{
										int x3[5];
										char ch;
									
									
									}s;
							
							}a4;
					}b;	
			
			}*p;
		
		}
		p=(union A *)malloc(sizeof(union A));
		
		p->b.a4.k=65;
		printf("%d ,%d ",p->b.a4.s.x3[0],p->y[0]);
		
void fun()
	{
		char c;
		if(c=getchar()!='\n')
			fun();
		printf("%c\n\n",c);
	
	}		
