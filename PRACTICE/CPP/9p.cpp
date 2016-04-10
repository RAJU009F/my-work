#include<iostream>
using namespace std;


void change(string* );

int main()
	{
		string s;
		cout<<"enter the string :";
		cin>>s;
		
		cout<<"string is: "<<s<<" length :"<<s.length()<<"\n";
		change(s);
	
		cout<<"string now is:"<<s<<"\n";
	
	}
	
void change(string* str)
	{
	char c=str[str.length()-1];
	str[str.length()-1]=str[0];
	str[0]=c;
	
	
	
	
	}	
	
