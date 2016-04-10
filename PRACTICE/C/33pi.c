#include<stdio.h>
#include<stdlib.h>

char word[4342];
struct T
	{
		char d;
		struct T *l;
		struct T *e;
		struct T *r;
		
		int end;
	
	
	};
	
struct T *insert(struct T *nn,char *w)
	{
		if(!nn)
			{
				struct T *nn=(struct T *)malloc(sizeof(struct T));
				nn->d=*w;
				
				//if(!*(w+1))
					//nn->end=1;
				nn->l=NULL;
				nn->r=NULL;
				nn->e=NULL;	
			
			
			}
		if(*w<nn->d)
			nn->l=insert(nn->l,w);
		else if(*w==nn->d)
			{
			if(*(w+1))
				nn->e=insert(nn->e,w+1);
			else
				nn->end=1;
			}				
		else
			nn->r=insert(nn->r,w);
		return nn;	
	
	
	
	}
int i=0;	
void dis(struct T *t)
	{
		if(!t)
			return ;
			
		dis(t->l);
		word[i]=t->d;
		if(t->end)
			{
				word[i]='\0';
				printf("%s",word);
			
			}		
		i++;
		dis(t->e);
		i--;
		dis(t->r);	
	
	
	
	
	}		
	
	
main()
	{
		struct T *t=NULL;
		
		t=insert(t,"hitler");
		
		dis(t);
	
	
	
	}	
