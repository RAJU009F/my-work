#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct E
	{
		char name[30];
		int age;
		float sal;
	
	
	
	};


E e1={"NAX",24,78000};
E e2={"RAJU",24,98340};

void modify_c(E *e)
	{
		strcpy(e->name,"Hitler");
		e->age=24;
		e->sal=67804;
	
	
	}

void modify_cpp(E &e)
	{
		
		strcpy(e.name,"nax");
		e.age=24;
		e.sal=97656;
		
	
	}
E& fun()
	{
		cout<<"E1 DEtails:"<<e1.name<<e1.age<<e1.sal<<endl;
		return e1;
	
	} 	
	
main()
	{
		//modify_c(&e1);	
		//cout<<"E1 DEtails:"<<e1.name<<e1.age<<e1.sal<<endl;
		//modify_cpp(e2);
		//cout<<"E1 DEtails:"<<e2.name<<e2.age<<e2.sal<<endl;
		
		fun()=e2;
		cout<<"E1 DEtails:"<<e1.name<<e1.age<<e1.sal<<endl;
		
		int i=10;
		const  int &j=i;
		
		cout<<j<<"   "<<i<<endl;
		
	j=40;
		
		cout<<j<<"   "<<i<<endl;
	}
