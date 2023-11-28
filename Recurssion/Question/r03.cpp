#include<iostream>
using namespace std;
int sumDigit(int n){
    // base case
    if( n==0){
        return 0;
    }
    // n=124     124%10 = 4  (gives last number)
    int num = n%10;
    // is last number ko add karege or iske sath ab ek kam digit ka number pass karege
    int ans = num + sumDigit(n/10);
    return ans;
}
int main(){
    int n;
    cout << "Enter a Digit : " << endl;
    cin >> n;
    int ans = sumDigit(n);
    cout << "Ans is : " << ans << endl;
}