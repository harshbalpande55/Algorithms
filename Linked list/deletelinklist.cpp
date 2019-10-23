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

int count(struct Node *headref)
{ int i=0;
  while(headref!=NULL)
  {
      i++;
      headref=headref->next;
  }
  return i;
}




void display(struct Node *headref)
{   cout<<"created linked list is :";
    while(headref!=NULL)
   {
     cout<< headref->data<<"\t";
     headref= headref->next;
   }
}

int delete_(struct Node *p,int index )
{  struct Node *t=  NULL;
   int x= -1;
   if(index<1 && index>count(p))
   {
       return -1;
   }
   if(index==1)
   {
       t=head;
       x=head->data;
       head=head->next;
       delete t;
       return x;

   }
   else
   { 
     for (int i=1;i<index-1;i++)
     {   t=p;
         p=p->next;
     }
     t->next = p->next;
     x=p->data;
     delete p;
     return x;
   }
   
}


int main()
{
  int A[]={10,20,30,40,50}; 
   create(A,5);
   delete_(head,2);
   

   display(head);
   return 0;
}