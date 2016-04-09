// Friend function in CPP

#include<iostream>
using namespace std;
class B;

class A{

	private:
		int number;
	public:
	friend int bridge(A, B);
	void setnum(int num)
		{
			number=num;
		}

};

class B{

	private:
		int number;
	public:
	friend int bridge(A, B);
	void setnum(int num);
		

};

void B::setnum(int num)
		{
		number = num;
		
		}
int bridge(A a, B b)
{
	
	return a.number + b.number;
	
}

int main()
{
	
	
	A a;
	a.setnum(10);
	B b;
	b.setnum(20);
	
	int res = bridge(a, b);
	cout<<"result:::"<<res;
	
	
}