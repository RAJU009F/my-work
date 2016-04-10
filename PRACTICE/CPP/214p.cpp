#include<iostream>
#include<string.h>
using namespace std;


class E
	
	{
		private:
			char n[232];
			int a;
			float sal;
			
		public:
			E()
				{
					strcpy(n,"");
					a=0;
					sal=0.0;
				
				}
			E(char *name,int x,int s)
				{
					strcpy(n,name);
					a=x;
					sal=s;
				
				
				}
				
			void show()
				
				{
					cout<<"Details:\n";
					cout<<"\nName:"<<n;
					cout<<"\nAge:"<<a;
					cout<<"\nSal:"<<sal;
				
				
				}
					
			~E()	
				{
					cout<<"\n\nDEs called\n\n";
				
				}
	
	
	
	
	
	};
main()
	{
		E *e1;
		e1=new E;
		e1->show();
		
		E *e=new E("NAX",24,67890.0);
		
		e->show();
		delete e1;
		
		e1=new E("hitler",4,45345.345);
		e1->show();
	
	
	}	
