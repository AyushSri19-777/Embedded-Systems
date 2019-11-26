#include <iostream>
#include <climits>
using namespace std;
int findMin(int *weights,bool *visited,int n)
{
    int minvertex=-1;
    for(int j=0;j<n;j++)
    {
        if(!visited[j]&&(minvertex==-1||weights[j]<weights[minvertex]))
        minvertex=j;
    }
    return minvertex;
}
void prims(int **edges,int n)
{
    int *weights=new int[n];
    int *parent=new int[n];
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        parent[i]=INT_MAX;
    }
    parent[0]=-1;
    weights[0]=0;
    for(int i=0;i<n-1;i++)
    {
        int minvertex=findMin(weights,visited,n);
        visited[minvertex]=true;
        for(int j=0;j<n;j++)   
        {
            if(edges[minvertex][j]!=0 && !visited[j])
            {
                if(edges[minvertex][j]<weights[j)
                {
                    weights[j]=edges[minvertex][j];
                    parent[j]=minvertex;
                }
            }
        }
    }
}


int main()
{
    int n,e;
    cout<<"Enter number of vertices and edges";
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        edges[i][j]=0;
    }
    cout<<"Enter edges and weights";
    for(int i=0;i<e;i++)
    {
        int f,s,w;
        cin>>f>>s>>w;
        edges[f][s]=w;
        edges[s][f]=w;        
    }
    prims(edges,n);


}