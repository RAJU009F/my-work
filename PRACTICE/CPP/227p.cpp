#include<iostream>

using namespace std;



class SLL
	{
		private:
			struct Node
				{
					int data;
					Node *next;
				
				}*p;
				
		public:
			SLL()
				{
					p=NULL;
					
				
				}		
			void append(int d);
			void append1(int d);
			void appendn(int d,int );
			void delet(int d);
			void display();
			int count();		
			~SLL();	
	};
void SLL::append(int d)
	{
		if(!p)
			{
				p=new Node;
				p->data=d;
				p->next=NULL;
				return;
			
			}
		Node *t,*q;
		q=p;
		while(q->next)
			{
				q=q->next;
				
			
			
			}
			t=new Node;
			t->next=NULL;
			t->data=d;
			q->next=t;
			
	
	}	
void SLL::append1(int d)
	{
		if(!p)
			{
				p=new Node;
				p->data=d;
				p->next=NULL;
				return;
			
			}
		Node *t=new Node;
		t->data=d;
		t->next=p;
		p=t;	
	
	
	}	
	
void SLL::appendn(int d,int cnt)
	{
	
		if(!p)
			{
			
					p=new Node;
				p->data=d;
				p->next=NULL;
				return;
			
			
			
			}
			
		Node *q,*r,*t;
		q=p;
		int k=1;	
		while(k<=cnt)
			{
				r=q;
				q=q->next;
				k++;
				if(!q)
				{
					cout<<"less Number of nodes";
					return;
				}
			
			}	
			
			
			t=new Node;
			t->data=d;
			t->next=q->next;
			q->next=t;
	
	
	
	
	
	}	
void SLL::delet(int d)
	{
		if(p->data=d)
			{
				Node *q=p;
				p=p->next;
				int d=q->data;
				delete q;	
				cout<<"\n\nNode: [ "<<d<<" ] deleted"<<endl;
			
			}
		else
			{
				Node *q,*r;
				
				q=p;
				
				while(q)
					{
						if(d==q->data)
							{
								r->next=q->next;
								delete q;
								cout<<"\n\nNode: [ "<<q->data<<" ] deleted"<<endl;
								return;
							
							}
						
						r=q;
						q=q->next;
					
					}
				if(!q)
					{
					
						cout<<"\n\nNot found\n\n";
					
					}
			
			
			
			}	
	
	
	
	
	}	
	
void SLL::display()
	{
		if(!p)
			{
			
				cout<<"\n\nList Empty\n\n";
				return;
			}
		Node *q=p;
		do
			{
					cout<<"[ "<<q->data<<" ] -";
					q=q->next;
			
			}while(q);
		cout<<"- NULL\n"<<endl;	
	
	}
	
int SLL::count()
	{
	
		if(!p)
			{
				return 0;
			
			}
			
		Node *q=p;
			int cnt=1;
			while(q->next)	
				{
					cnt++;
					q=q->next;
				
				}
	
	
		return cnt;
	}		
SLL::~SLL()
	{
		if(p)
			{
				Node *q;
				
				while(p)
					{
						q=p;
						delete p;
						p=q->next;
					
					
					}
			
			
			
			}
	
	
	
	
	
	}
	
main()
	{
		SLL l1;
		for(int i=0;i<=10;i++)
			l1.append(i);
			
		l1.append1(100);
		l1.appendn(200,6);
		
		l1.display();
		
		l1.delet(9);
		l1.display();	
		cout<<l1.count()<<endl;
	
	
	}		
	
