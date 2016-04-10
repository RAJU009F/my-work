#include<iostream>
using namespace std;


class sample
	{
		private:
			static int count;
		public:
		sample()
			{
			
				count=10;
			}	
			
		void dis()	
			{
				cout<<endl<<"count"<<count<<endl;
			}	
	
	
	};
int sample::count;	
	
main()
	{
		sample s1,s2,s3;
	
		s1.dis();
		s2.dis();
		s3.dis();	
	
	}	
