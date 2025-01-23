#include<iostream>
using namespace std;
void permutation(string name,string ans,int index){
    if(index>=name.length()){
        cout << ans << endl;
        return;
    }
    
}
int main(){
    string name = "abc";
    string ans = "";
    permutation(name,ans,0);
}