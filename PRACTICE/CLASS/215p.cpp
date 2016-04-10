#include<iostream>


using namespace std;


class M
	{
		private :
			int r,c;
			int *p;
			
		public:
			M(int a,int b)
				{
					r=a;
					c=b;
					p=new int(r*c);
				
				}	
				
			void get_mat()
				{

					int i,j,off;
					
					cout<<"Enter Mat Elemnts:"<<endl;
					
					for(i=0;i<r;i++)
						{
							for(j=0;j<c;j++)
								{
									
								off=i*c+j;
								cin>>p[off];
								
								
								}
						
						
						}
				}	
				
				
		void print_mat()
			{
			
			
				int i,j,off;
				cout<<"Elements are:"<<endl;
				
				for(i=0;i<r;i++)
					{	
						cout<<"\n";
						for(j=0;j<c;j++)
							{
								off=i*c+j;
								cout<<"\t"<<p[off];
							
							
							}
					
					
					}	
			
			
			
			}	
			
		M operator +(M m)
			{
			
				M t(r,c);
				int i,j,off;
				for(i=0;i<r;i++)
					{
						for(j=0;j<c;j++)
							{
								off=i*c+j;
								t.p[off]=p[off]+m.p[off];
							
							
							
							
							}
					
					
					} 
			
			
			
				return t;
			
			}	
			
			
		M operator *(M m)
			{
				M t(m.c,r);
				int i,j,k,off,off1,off2;
				for(i=0;i<t.r;i++)
					{
						for(j=0;j<t.c;j++)
							{
								off=i*t.c+j;
								t.p[off]=0;
								
								for(k=0;k<m.r;k++)
									
									{
										off1=i*c+k;
										off2=k*m.c+j;
								
										t.p[off]+=p[off1]*m.p[off2];
									}
							
							}
					
					}
				
					return t;
				
			
			
			
			}			
	
	};
main()
	{
		M a(4,3),b(3,4);
		a.get_mat();
		b.get_mat();
		M c(4,4) ;
		c=a*b;
		c.print_mat();	
	
	
	}
