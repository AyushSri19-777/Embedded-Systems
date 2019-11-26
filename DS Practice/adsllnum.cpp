#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class node
{
      node *next;
    int info;
public:
    node *insertend(node *,int);
    void display(node *);
    node *recADD(node*);
    void add(int,int);
};
node *node::recADD(node *A)
{
    node *head;
    if(A->next=NULL)
        return A;
    else
    {
        head=A;
         head->next=recADD(A->next);
    }
}

node *node::insertend(node *start,int k)
{
    node *temp=new node;
    node *cur=start;
    temp->next=NULL;
    temp->info=k;
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
void node::add(int x,int y)
{
    node *a=NULL,*b=NULL,*c=NULL;
    while(x!=0)
    {
        a=insertend(a,x%10);
        x/=10;
    }
    node *F=NULL;
    F=recADD(a);
    while(y!=0)
    {
        b=insertend(b,y%10);
        y/=10;
    }
    node *cur1=a,*cur2=b;
    while(cur1!=NULL&&cur2!=NULL)
    {
        if(cur1->info+cur2->info>9)
        {
            c=insertend(c,(cur1->info+cur2->info)-10);
            if(cur1->next!=NULL)
            (cur1->next)->info++;
            else if(cur2->next!=NULL)
                (cur1->next)->info++;
            else
                c=insertend(c,1);
        }
        else
            c=insertend(c,(cur1->info+cur2->info));
        cur1=cur1->next;
        cur2=cur2->next;
    }
     cout<<"\na:\n";
    display(a);
    node *C=recADD(a);
    display(C);
     cout<<"\nb:\n";
    display(b);
    cout<<"\nAnswer:\n";
    display(c);
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
    node n;
    n.add(864,372);
}
