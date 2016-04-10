#include<iostream>
using namespace std;

struct SLL
	{
		int data;
		SLL *next;
	
	};
class Q
	{
	
		private:
			SLL *rear,*front;
		public:
			Q()
				{
					front=rear=NULL;
				
				
				}	
				
			void nq(int d)
				{
					SLL *t=new SLL;
						t->data=d;
						t->next=NULL;
						
						if(!front)
							{
								front=rear=t;
								
								return;	
							}
						rear->next=t;
						rear=t;	
							
							
				
				
				
				}	
			int dq()
				{
					if(!front)
						{
							cout<<"Q empty\n\n";
							return -1;
						
						}	
					SLL *t=front;
					int item=t->data;
					front=front->next;
					delete t;
					if(!front )
						{
							front=rear=NULL;
						
						}	
					return item;
				
				}	
				
			~Q()
				{
					if(front)
						{
							SLL *t=front;
							delete t;
							front=front->next;
						
						
						
						
						}
				
				}	
	
	
	};
	
	main()
		{
			Q q;
			for(int i=0;i<10;i++)
					q.nq(i);
			for(int i=0;i<12;i++)
				cout<<q.dq()<<endl;
		}
