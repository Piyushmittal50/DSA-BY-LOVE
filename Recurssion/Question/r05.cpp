#include<iostream>
using namespace std;
int fact(int n){
    if(n==2){
        return 2;
    }
    int choti = fact(n - 1);

    int badi = n * choti;
    
    return badi;
}
int main(){
    int n;
    cout << "Enter a Num : " << endl;
    cin >> n;
    int ans = fact(n);
    cout << "Ans is : " << ans << endl;
}