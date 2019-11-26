#include <iostream>
#include <queue>
using namespace std;

void printBFS(int **A,int s,int V)
{
    queue<int> q;
    bool *visited=new bool[4];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    q.push(s);
    visited[s]=true;
     while(!q.empty())
    {
        int popp=q.front();
            q.pop();
            cout<<popp<<"\t";
        for(int i=0;i<V;i++)
        {
            if(A[popp][i]==1 && !visited[i])
            {
                   q.push(i);
                   visited[i]=true;
            }
        }
    }
}

int main()
{
    int V,E;
    cin>>V>>E;

    int** A=new int*[V];

    for(int i=0;i<V;i++)
    {
        A[i]=new int[V];
        for(int j=0;j<V;j++)
        {
            A[i][j]=0;
        }
    }
    cout<<"Enter the edge vertices";
    for(int i=0;i<E;i++)
    {
        int sv,ev;
        cin>>sv>>ev;
        A[sv][ev]=1;
        A[ev][sv]=1;
    }
    int s;
    cout<<"Enter the source vertex";
    cin>>s;
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
    visited[i]=false;
    printBFS(A,s,V);
}
