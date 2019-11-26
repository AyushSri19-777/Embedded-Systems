#include<bits/stdc++.h>
using namespace std;

int findit(int* distance ,bool* visited , int v){
    int minVertex  = -1;
    for(int i = 0;i<v;i++){
        if(!visited[i]&&(minVertex == -1 ||distance[i]<distance[minVertex])){
            minVertex = i;
        }
    }

    return minVertex;
}

void djikstra(int** edges , int v){
    bool* visited = new bool[v];
    int* distance = new int[v];
    for(int i = 0;i<v;i++){
        visited[i] = false;
        distance[i] = INT_MAX;
    }

    distance[3] = 0;

    for(int i = 0;i<v;i++){
        int minVertex = findit(distance,visited,v);
        visited[minVertex] = true;
        for(int j = 0;j<v;j++){
            if(!visited[j]&&edges[minVertex][j]!=0){
                distance[j] = min(distance[j],distance[minVertex]+edges[minVertex][j]);
            }
        }
    }

    for(int i = 0;i<v;i++){
        cout << i << " " << distance[i] << endl;
    }
}

int main(){
    int v,e;
    cin >> v >> e;
    int** edges = new int*[v];
    for(int i = 0;i<v;i++){
        edges[i] = new int[v];
        for(int j = 0;j<v;j++){
            edges[i][j] = 0;
        }
    }

    for(int i = 0;i<e;i++){
        int f,s,w;
        cin >> f >> s >>w;
        edges[f][s] = w;
        //edges[s][f] = w;
    }

    djikstra(edges,v);
}
