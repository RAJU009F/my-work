#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

const int a=20;
const int *f();

struct E
		{
			char name[34];
			int age;
			float sal;
		
		};
E e1={"Aditya",34,464546456.4545};
E e2={"NAaxlite",45,4534534534453};		
E& fun();		

main()
	{
		int const *p;
		
		p=f();
		cout<<*p<<endl;
		
		int a=90;
		{
			int a=80;
			cout<<a<<::a<<::a;
			cout<<"nax\n\n";
		}
		
		fun()=e1;
		
		cout<<e2.sal<<e2.name<<e1.age;
		char t[]="indian";
		int i=strlen(t);
		cout<<"len=="<<i;
			
	
	}
const int *f()
	{
		return &a;
	
	
	}	
E &fun()
	{
	
	E e={"erwrw",45,45345634534};
	return e;
	
	}	
