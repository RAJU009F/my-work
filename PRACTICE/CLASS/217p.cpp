#include<iostream>

using namespace std;


class S
	{
		private:
			static float d;
			int a;
			char b;
			int c;
			
			
			
		public:
		
			void dis()
				{
					cout<<a<<b<<c<<endl;
				}	
	
	
	
	};
float S::d=0;	
	
main()
	{
	
		cout<<sizeof(S)<<endl;
		S s;
		cout<<sizeof(s)<<sizeof(float)<<endl;
		s.dis();
	
	
	
	}	
