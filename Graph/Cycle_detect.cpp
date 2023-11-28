//   Cycle Detection in Undirected Graph
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class solution{
    bool detect(int src,vector<int> adj[],int vis[]){
        vis[src] = 1;

        // store < source node, parent node >
        queue<pair<int,int>> q;
        q.push({src,-1});

        // traverse queue untill it becomes empty
        while(!q.empty()){
            int frontNode = q.front().first;
            int parent = q.front().second;
            q.pop();

            // now go to its all adjcent node
            for(auto adjNode : adj[frontNode]){
                // if adjecent node is unvisited 
                if(!vis[adjNode]){
                    vis[adjNode] = 1;
                    q.push({adjNode,frontNode});
                }
                 // if adjecent node is visited and but it is not its own parent node
            else if(parent !=adjNode){
                // yes it is a cycle
                return true;
            }
            }
        }
        // there is no cycle
        return false;
    }
    public:
    bool iscycle(int v, vector<int> adj[]){
        int vis[v] = {0};
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(detect(i,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};
int main(){
    // v = 4 , e = 2
    vector<int> adj[4] = {{},{2},{1,3},{1,2}};
     solution obj;

    bool ans = obj.iscycle(4,adj);

    if(ans){
        cout<<"--> cycle is present -->"<<endl;
    }
    else{
        cout<<" --> cycle is absent -->"<<endl;
    }
}