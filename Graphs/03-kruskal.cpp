#include <bits/stdc++.h>
using namespace std;

class Edge
{
    public:
    int s;
    int d;
    int w;
};

int findParent(int v,int *parentOf)
{
    if(parentOf[v]==v)
    return v;
    else
    {
        return findParent(parentOf[v],parentOf);
    }

}
bool compare(Edge E1,Edge E2)
{
    return E1.w<E2.w;
}
void printKruskal(Edge E1[],int E,int V)
{
    sort(E1,E1+E,compare);
    int *parentOf=new int[V];
    for(int i=0;i<V;i++)
    {
        parentOf[i]=i;
    }
    Edge MST[V-1];
    int k=0;;
    for(int i=0;i<E;i++)
    {
        int parentS=findParent(E1[i].s,parentOf);
        int parentD=findParent(E1[i].d,parentOf);
        if(parentD!=parentS)
        {
            MST[k++]=E1[i];
        }
        if(k==V-1)
        break;
    }
    for(int i=0;i<V-1;i++)
    cout<<MST[i].s<<"\t"<<MST[i].d<<"\n";
}


int main()
{
    int E,V;
    cout<<"Enter the number of edges and vertices";
    cin>>E>>V;
    cout<<"Enter edge and weights";
    Edge E1[E];
    for(int i=0;i<E;i++)
    {
        cin>>E1[i].s>>E1[i].d>>E1[i].w;
    }

    printKruskal(E1,E,V);

}
