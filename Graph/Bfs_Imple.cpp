// for undirected graph

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class solution{
   public:
   vector<int> bfsofgraph(int v,vector<int> adj[]){
    int visited[v] = {0};
    visited[0] = 1;
    queue<int> q;

    q.push(0);

    vector<int> ans;

    while(!q.empty()){
        int topnode = q.front();
        q.pop();

        ans.push_back(topnode);

        for(auto it: adj[topnode]){
            if(!visited[it]){
                visited[it]=1;
                q.push(it);
            }
        }
    }
    return ans;
   }
};

void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printans(vector<int> &ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
   vector<int> adj[6];

   addedge(adj,0,1);
   addedge(adj,1,2);
   addedge(adj,1,3);
   addedge(adj,0,4);

   solution obj;
   vector<int> ans = obj.bfsofgraph(5,adj);
   printans(ans);
}