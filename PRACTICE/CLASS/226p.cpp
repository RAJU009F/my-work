#include<iostream>
#define MAX 10
using namespace std;

class CQ
	{
		
		private:
			int front,rear;
			int a[MAX];
			
		public:
		
			CQ()
				{
					front=-1;
					rear=-1;
				
				
				
				
				}
			void enqueue(int d)
				{
					if(isFull())
						{
							cout<<"\n\nQueue is Full\n\n";
							return;
						
						}
						
					a[(++rear)%MAX]=d;
					
					if(front==-1)
						front=0;
				
				}	
				
			int dqueue()
				{
					if(isEmpty())
						{
							cout<<"\n\nQueue is Empty\n\n";
							return -1;
						
						
						
						}
					int d=a[front];
						if(front==MAX-1)
							{
								front=0;
							}	
						else
							{		
								if(front==rear)
									front=rear=-1;
								else
									front++;
							}			
					
					return d;
				
				}	
				
			int isFull()
				{
					return ((rear==MAX-1 && !front) || rear+1==front);
				
				
				}	
				
			int isEmpty()
				{
					return front==-1;
				
				}	
	
	
	
	
	};

int main()
	{
		
		CQ q1;
			for(int i=0;i<11;i++)				
				q1.enqueue(i);
			for(int i=0;i<14;i++)		
				cout<<q1.dqueue()<<endl;
				
		
		return 0;
	
	
	}
