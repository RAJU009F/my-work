#include<iostream>

using namespace std;


class date
	{
		private:
			int dd,mm,yy;
			
		public:
			date()
				{
				
					dd=0;
					mm=0;
					yy=0;
					
				
				}	
				
			date(int d,int m,int y)
				{
				
					dd=d;
					mm=m;
					yy=y;
				
				}	
				
			date& operator=(const date&);
			date(date&);
			
			void disp();	
		
	};	
	
date& date::operator=(const date & d)
	{
		dd=d.dd;
		mm=d.mm;
		yy=d.yy;
		return *this;
	
	
	}	
	
date::date(date &d)
	{
		dd=d.dd;
		mm=d.mm;
		yy=d.yy;
	
	}	
	
void date::disp()	
	{
	
		cout<<"\n"<<dd<<"-"<<mm<<"-"<<yy<<endl;
	
	}	
	
	main()
		{
			date d1,d2(6,7,13);
			
			d1=d2;
			
			date d3=d1;
			
			d1.disp();
			d2.disp();
			d3.disp();
			
		
		}
