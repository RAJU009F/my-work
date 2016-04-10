#include<iostream>

using namespace std;



class circle
	{
		private:
			int r;
			float x;
			float y;
			
			
		public:
		
			circle()
				{
					
					r=0;
					x=0;
					y=0;
				
					
				}
			circle(int ra,float X,float Y)
				{
				
					r=ra;
					x=X;
					y=Y;
				
				
				
				}
			void show()
			
				{
				
					cout<<"\n\nRadius:"<<r<<endl;
					cout<<"X , Y"<<x<<" , "<<y<<endl;
				
				
				}	
				
				
			circle &operator =(circle &c)	
				{
					cout<<"assignment operator invoked:\n\n";
					
					r=c.r;
					x=c.x;
					y=c.y;
					
					return *this;
				
				}
				
			circle(circle &c)
				{
					cout<<"copy constructor invoked:\n\n";
					r=c.r;
					x=c.x;
					y=c.y;
				
				}	
	
	};
	
main()
	{
	
		circle c1(10,33.4,67.5),c2,c4;
		c2=c4=c1;
		
		circle c3=c1;
		
		
		c1.show();
		c2.show();
		c3.show();
		c4.show();
	
		int a=98.07;
		double b;
		b=a;
		cout<<a<<"sizeof "<<sizeof(double)<<endl;
	
	}	
