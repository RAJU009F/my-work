#include<iostream>

using namespace std;

struct SLL
	{
		int data;
		SLL *next;
	
	};
class S
	{
		private:
			SLL	*top;
		public:
			S()
				{
					top=NULL;
				
				}
		
		
			void push(int d)
				{
					if(!top)
						{
							top=new SLL;
							top->data=d;
							top->next=NULL;
							return ;
						
						}
						
					SLL *t=new SLL;
					if(!t)
						{
							cout<<"Stack is Full\n\n";
							return;
						}
					t->data=d;
					t->next=top;
					top=t;	
				
				}	
				
			int pop()
				{
					if(!top)
						{
						cout<<"\nEmpty\n";
						return -1;
						
						
						}
					SLL *t=new SLL;
					t=top;
					int item=t->data;
					top=top->next;
					delete t;
					return item;
					
				
				}	
				
			void disp()
				{
					if(top)
						{
							SLL *t=top;
							while(t)
								{
									cout<<"[ "<<t->data<<" ]"<<endl;
									t=t->next;
								
								}
							
						
						}
				
				}	
				
			~S()
				{
					if(top)
						{
							SLL *t;
							while(top)
								{
									t=top;
									
									top=top->next;
									delete t;
								
								}
						
						
						
						
						}
				
				
				}	
	
	
	
	
	};
	
	main()
		{
			S s1;
			for(int i=0;i<10;i++)
				s1.push(i*10);
				
			s1.disp();	
			
			s1.pop();
			s1.disp();
			
		
		
		}
		
	
