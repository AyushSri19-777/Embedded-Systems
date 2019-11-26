#include <iostream>
#include <stdio.h>
using namespace std;
class dnode
{
    dnode *next,*prev;
    int info;
public:
    dnode *insend(dnode*);
    dnode *insbeg(dnode*);
    dnode *delbeg(dnode*);
    void disp(dnode*);
};
void dnode::disp(dnode *start)
{
    dnode *cur=start;
    while(cur->next!=NULL)
    {
        cout<<cur->info<<"-->";
        cur=cur->next;
    }
    cout<<cur->info;
    cout<<"\nReverse print\n";
    while(cur!=start)
    {
        cout<<cur->info<<"-->";
        cur=cur->prev;
    }
}
dnode *dnode::insbeg(dnode *start)
{
    dnode *temp=new dnode;
    cout<<"Enter the element ";
    cin>>temp->info;
    if(start==NULL)
    {
        start=temp;
        temp->next=NULL;
        temp->prev=NULL;
        return start;
    }
    temp->next=start;
    start->prev=temp;
    start=temp;
    return start;
}
dnode *dnode::insend(dnode *start)
{
    dnode *temp=new dnode;
    dnode *cur=start;
    cout<<"Enter the element ";
    cin>>temp->info;
    if(start==NULL)
    {
        start=temp;
        temp->next=NULL;
        temp->prev=NULL;
        return start;
    }
    while(cur->next!=NULL)
        cur=cur->next;
    cur->next=temp;
    temp->prev=cur;
    return start;
}
dnode *dnode::delbeg(dnode *start)
{
    if(start==NULL)
        return start;
    dnode *cur=start->next;
    cur->prev=NULL;
    delete start;
    start=cur;
    return start;
}
int main()
{
    dnode *start=NULL,d;
    int ch;
    for(;;)
    {
        cout<<"Enter \n1.Insert at end\n2.Insert at beginning\n3.Delete from beginning\n4.Display";
        cin>>ch;
        switch(ch)
        {
            case 1:start=d.insend(start);
                break;
            case 2:start=d.insbeg(start);
                break;
            case 3:start=d.delbeg(start);
                break;
            case 4:d.disp(start);
                break;
        }
    }
}
