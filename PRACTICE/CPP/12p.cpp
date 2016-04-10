#include<iostream>
#include<iomanip>
using namespace std;

string* newx();

int main()
	{
	string* s;
	s=newx();
	cout<<"string is:"<<*s;
	//delete s;
	
	cout<<setw(5)<<"string is:"<<*s;
	
	}
	
string* newx()
	{
		string* ps=new string("naxalite");
		return ps;
	
	
	
	}	
