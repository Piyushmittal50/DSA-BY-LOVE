// representation for unwaighted graph
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the Nodes And Edges -> "<<endl;
    cin>>n>>m;

    // it takes as space o(n*m)  which is very expensive and lot of space is wasted
    // int adj[n+1][m+1];  // 0-based indexing
    // for(int i=0;i<m;i++){
    //     int u,v;
    //     cin>>u>>v;
    //     adj[u][v] = 1;   // intersection mark as 1
    //     adj[v][u] = 1;   // reverse intersection mark as 1
    // }


    // thats why we use list ( basically vector array)
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;                        // basically it for undirected graph

        // and the space taken by is o(2*E)
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;                        // basically it for directed graph

        // and the space taken by is o(E)
        cin>>u>>v;
        adj[u].push_back(v);
    }

}