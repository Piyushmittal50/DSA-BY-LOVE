#include<iostream>
using namespace std;
void subsequence(string name,string ans,int index){
    if(index >=name.length()){
        cout << ans <<endl;
        return;
    }

    // exclude
    subsequence(name, ans, index + 1);

    // include
    ans = ans + name[index];
    subsequence(name, ans, index + 1);
}
int main(){
    string name = "ab"; // find subsequence
    string ans = "";
    subsequence(name,ans,0);
}