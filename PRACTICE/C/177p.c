#include<stdio.h>
#include<stdlib.h>

struct SLL
    
    {
        int data;
        
        struct SLL *next;
    
    
    
    };
    
    
struct SLL *nn(int d)
    {
    
        struct SLL *node=(struct SLL *)malloc(sizeof(struct SLL));
        
        node->next=NULL;
        node->data=d;
        return node;
    
    
    }
    
void insert(struct SLL **head,int d)
    {
        if(!*head)
            {
            
            *head=nn(d);
                return;
            
            }
         
        struct SLL *t=nn(d); 
        t->next=*head;
         *head=t;     
    
    
    }    
    
void display(struct SLL *head)
    {
    
        if(!head)
            printf("Empty");
            
            
        while(head)
            {
                printf("[%d]-",head->data);
                head=head->next;
            }    
          printf("-NULL\n\n");  
    
    }    
main()
    {
        struct SLL *h=NULL;
        
        insert(&h,4);
        insert(&h,5);
        insert(&h,9);
        display(h);
    }    
    
    
    
    
