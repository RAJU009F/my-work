
#include<iostream>
using namespace std;

class B
	{
		private:
			int xb;
		public:
			
			B()
				{
				xb=90;
				}	
			
			virtual void n()
				{
				
				cout<<"nax";
				}
			
	
	};
class D1: public B
	{
		protected:
			int xd;
		public:
			D1()
				{
					xd=0;
				
				}
			void n()
				{
				
				cout<<"indian hitler";
				
				}	
	
	
	};	
	
main()
	{
		B *b;
		D1 d;
		cout<<sizeof(b)<<endl;
		cout<<sizeof(d)<<endl;
		b=&d;
		b->n();
	
	}	
