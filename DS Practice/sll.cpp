#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class node
{
      node *next;
    int info;
public:
    node *insertend(node *);
    node *rev(node *);
    void display(node *);
    node *Solution(node *,int);
};
node *node::Solution(node* A, int B)
{
    node *cur=A,*J,*prev;
    node *temp=new node;
    J=temp;
    int c=0;
    node *cur2=J;
    while(cur->next!=NULL)
    {
        c=1;
        while(c==B)
        {
             node *temp=new node;
             temp->info=(cur->info);
             cur2->next=temp;
             cur2=cur2->next;
             c++;
             cur=cur->next;

        }
        prev=cur;
        cur=cur->next;
        prev->next=NULL;
        J=rev(J);
        cur2=J;
        while(cur2->next!=NULL)
        cur2=cur2->next;
    }
    cur2=J->next;
    J->next=NULL;
    delete J;
    J=cur2;
    return J;
}
node *node::insertend(node *start)
{
    node *temp=new node;
    node *cur=start;
    temp->next=NULL;
    cout<<"Enter the element";
    cin>>temp->info;
    if(start==NULL)
        start=temp;
    else if(start->next==NULL)
    {
        start->next=temp;
        temp->next=NULL;
    }
    else
    {
        while(cur->next!=NULL)
            cur=cur->next;
        cur->next=temp;
        temp->next=NULL;
    }
    return start;
}
node *node::rev(node *start)
{
    node *p=start,*q;
    start=NULL;
    while(p!=NULL)
    {
        q=p->next;
        p->next=start;
        start=p;
        p=q;
    }
   return start;
}
void node::display(node *start)
{
    node *cur=start;
    int c=0;
    while(cur!=NULL)
    {
        cout<<cur->info<<"-->";
        cur=cur->next;
        c++;
    }
    cout<<"Count= "<<c;
}
int main()
{
    node n,*start=NULL,*k;
    for(;;)
    {
        int ch;
        cout<<"Enter 1.Add at end 2. Display 3.Reverse 4.Soluchan";
        cin>>ch;
        switch(ch)
        {
            case 1:start=n.insertend(start);
                    break;
            case 2:n.display(start);
                   break;
            case 3:k=n.rev(start);
                n.display(k);
                    break;
            case 4:start=n.Solution(start,2);
                    break;
        }
    }
}

