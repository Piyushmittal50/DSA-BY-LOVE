#include<iostream>
using namespace std;
int natural(int n){
    if(n==1)
        return 1;
    int ans = n + natural(n - 1);
    return ans;
}
int main(){
    int n;
    cout << "Enter a number : " << endl;
    cin >> n;

    int ans = natural(n);
    cout << "Ans is : " << ans << endl;
}