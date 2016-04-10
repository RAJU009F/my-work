#include<iostream>
using namespace std;
void rev();
int main()
	{
		//cout<<"rev:"<<rev()<<endl;
		rev();
	
	}	
	
	
void rev()
	{
		string s;
		char c;
		cin.get(c);
		if(c=='\n')
			return;
		rev();
		cout<<c;
	
	
	}	
