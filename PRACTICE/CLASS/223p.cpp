
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

class mystring
	{
		private:
			char str[343];
			
		public:
			mystring()
				{
					str[0]='\0';
				
				}	
				
			mystring(char * s)
				{
				
				strcpy(str,s);
				}
			mystring(int a)	
				{
				
					sprintf(str,"%f",a);
					//itoa(a,str,10);
				
				}		
				
			operator int()
				{
					int r=0;
				char *str1=str; 
					
					while(*str1)
						{
							r=r*10+*str1-'0';
							str1++;
						
						}	
						
					return r;	
			
			
				}	
				
			void show()
				{
					cout<<endl<<str<<endl;
				
				}		
	
	};
	
main()
	{
		mystring s1;
		s1=122334;
		s1.show();
	
	mystring s2("576");
	int i=int(s2);
	
	cout<<i<<endl;
	
	
	}	
