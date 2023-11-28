#include<bits/stdc++.h>
using namespace std;
class solution {
    bool dfs(int node,int parent,int vis[],vector<int> adj[]){
        vis[node] = 1;
        // visit its adjecent nodes
        for(auto adjNode : adj[node]){
            // unvisited adjecent node
            if(!vis[adjNode]){
                if(dfs(adjNode,node,vis,adj)==true)
                return true;
            }
            // visited node but not parent node
            else if(adjNode !=parent)  return true;
        }
        return false;
    }
  public:
  bool iscycle(int v,vector<int> adj[]){
    int vis[v] = {0};
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(dfs(i,-1,vis,adj)==true)
                return true;
        } 
    }
    return false;
  }
};
int main(){
   vector<int> adj[4] = {{},{2},{1,3},{2}};
   solution obj;

   bool ans = obj.iscycle(4,adj);
   if(ans)
    cout<<"cycle is present -->"<<endl;
    else
    cout<<"cycle is absent -->"<<endl;
}