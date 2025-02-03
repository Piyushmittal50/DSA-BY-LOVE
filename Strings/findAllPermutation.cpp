#include<iostream>
#include<vector>
using namespace std;
void permutation(string name,string ans,vector<bool> &visited){
    if (ans.length() == name.length()){
        cout << ans << " ";
        return;
    }
    for (int i = 0; i < name.length();i++){
        if(!visited[i]){
            visited[i] = true;
            permutation(name, ans + name[i], visited);

            // backtrack
            visited[i] = false;
        }
    }
}
int main(){
    string name = "abc";
    vector<bool> visited(name.length(),false);
    permutation(name,"",visited);
}