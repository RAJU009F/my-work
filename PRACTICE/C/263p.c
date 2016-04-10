#include<stdio.h>
#include<stdlib.h>
struct G
	{
		int V;
		int E;
		struct SLL *A;
	
	
	};
struct SLL
	{
	
		int v;
		struct SLL *next;
	
	
	};	
	
struct G *create()	
	{
		int i;
		struct G *g=(struct G *)malloc(sizeof(struct G));
		printf("\nEnter number of vertices:: and Edges::");
		scanf("%d%d",&g->V,&g->E);
		
	//	g->A=malloc(g->V*sizeof(struct SLL));
		for(i=0;i<g->V;i++)
			{
				g->A[i]=(struct SLL *)malloc(sizeof(struct SLL));
				g->A[i]->next=g->A[i];
				g->A[i]->v=i;
			
			}
		//for(i=0;i<g->E;i++)
			
		
	
	
	return g;
	
	}
	main()
		{
			struct G *g=create();
			
				
				
				}		
			
					
		
		}	


