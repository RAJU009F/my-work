#include<iostream>
using namespace std;

int Ispol(string );
string  rev(string);

int main()
	{
		string s;
		cout<<"enter the string :";
		cin>>s;
		
		cout<<"string is: "<<s<<" length :"<<s.length()<<"\n";
	
		if(Ispol(s))
			cout<<"POLIN\n";
		else
			cout<<"NOT POLIN\n";
		s=rev(s);
		cout<<"reverseof string is:"<<s<<"\n";		
	
	
	}
	
int Ispol(string str)
	{
		int j=str.length()-1;
		int i=0;
		while(str[i]==str[j])
			{
				if(i==j)
					return 1;
				i++;
				j--;
			
			
			}
		
		
		
		return 0;
	
	
	}
string rev(string str)
	{
		int j=str.length()-1;
		int i=0;
		while(1)
			{
				if(i>=j)
					break;
				char c=str[i];
				str[i]=str[j];
				str[j]=c;
				i++;
				j--;	
			
			
			
			}
	
		return str;
	
	
	}		
