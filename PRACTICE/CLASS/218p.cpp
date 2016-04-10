#include<iostream>
using namespace std;



class date
	{
		int dd,mm,yy;
		
		public:
			date()
				{
				
					cout<<"Reached date\n\n";
				
				}
			
	
	
	};
	
main()
	{
		date t;
		date *t1=new date;
		
		cout<<*t1<<endl;
	
	
	}	
