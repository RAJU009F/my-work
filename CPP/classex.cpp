#include<iostream>
using namespace std;


class Student
	{
	private:
	int roll;
	
	public:
	string name;
	void display();
		
	int getRoll()
		{
		return roll;
		}
	void setRoll(int i)
		{
		roll = i;
		}
	
	
	};
void Student::display()
	{
		cout<<"RN::" <<getRoll()<<"Name::"<<name;
	
	
	}



int main()
	{
	
	Student A;
	A.setRoll(100);
	A.name = "NAX";
	A.display();
	
	return 0;
	}