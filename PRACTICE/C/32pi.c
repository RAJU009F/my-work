#include<stdio.h>
#include<stdlib.h>

struct T 
	{
		char d;
		int end;
		
		struct T *child[26];
	
	
	
	};
struct T *insert(struct T *t,char *w)
	{
		if(!*w)
			return NULL;
		if(!t)
			{
				struct T *nn=(struct T *)malloc(sizeof(struct T));
				nn->d=*w;
					int i;
					for(i=0;i<26;i++)
						{
							nn->child[i]=NULL;
						
						
						}
				if(!*(w+1))
					nn->end=1;
				else
					nn->child[*w]=insert(nn->child[*w],w+1);
				return nn;							
			
			}	
		t->child[*w]=insert(t->child[*w],w+1);

			return t;	
	
	
	}

void print(struct T *t)
	{
		if(t)
		{
			printf("%c",t->d);
			int i=0;
			print(t->child[t->d]);
			for(i;i<26;i++)
				print(t->child[i]);
			
		}	
			
	
	
	
	}
	
int search(struct T *t,char *w)	
		{
			if(!t)
				return -1;
			if(!*w)
				{
					if(t->end==1)
						return 1;
					else
						return -1;	
				
				
				
				}
			if(t->d==*w)
				return search(t->child[*w],w+1);
				
			else	
				return -1;	
						
		
		
		
		}
	
main()
	{
		struct  T *t=NULL;
		
		t=insert(t,"nax");
		t=insert(t,"hitler");
		
		
		print(t);
		if(search(t,"nax"))	
			printf("\n\nfound::\n\n");	
	
	
	
	}	


