#include <iostream>
using namespace std;
void printDFS(int** A,int s,int V,bool *visited)
{
    cout<<s<<"\t";
    visited[s]=true;
    for(int i=0;i<V;i++){
    if(A[s][i]==1 && !visited[i])
        printDFS(A,i,V,visited);
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
    printDFS(A,s,V,visited);
}
