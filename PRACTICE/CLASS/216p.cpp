#include<iostream>

using namespace std;

class L
	{
			private:
				class node
					{
						public:
						int data;
						node *link;
					
					}*p;
	
			public:
				void create()
					{
						p=new node;
						p->data=10;
					
					
					}
				void show()
					{
						cout<<p->data<<endl;
					
					
					}
				
	};

main()
	{
		L l;
		l.create();
		l.show();		
	return 0;
	
	}
