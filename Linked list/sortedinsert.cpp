#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*head=NULL;

void create(int A[],int n)
{
   struct Node *new_node,*last;
   head = new Node;
   head->data =A[0];
   head->next=NULL;
   last=head;

   for (int i=1;i<n;i++)
   {
       new_node= new Node();
       new_node->data=A[i];
       new_node->next=NULL;
       last->next=new_node;
       last=new_node;
   }
}



void display(struct Node *headref)
{   cout<<"created linked list is :";
    while(headref!=NULL)
   {
     cout<< headref->data<<"\t";
     headref= headref->next;
   }
}

void sortedinsert(struct Node *headref,int value)
{   struct Node *t,*tailingptr=NULL;
    t=new Node();
    t->data = value;
    t->next =NULL;
    if(head==NULL)
    { 
      head= t;
    }
    else
    {  while(headref && (headref->data)< value)
        {
           tailingptr=headref;
           headref=headref->next;
        }
        if(headref==head)
        {
          t->next=head;
          head=t;
        }
        else
        {
            t->next=tailingptr->next;
            tailingptr->next=t;
        }
        
    }
    
}


int main()
{
  int A[]={10,20,30,40,50}; 
   create(A,5);
   sortedinsert(head,55);

   display(head);
   return 0;
}
