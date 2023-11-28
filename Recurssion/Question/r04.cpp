#include<iostream>
using namespace std;
bool prime(int n, int i = 2)
{
    if(n<=1) return false;
    if(n==2) return true;
        if (n % i == 0)
        {
            return false;
        }

        if(i*i > n)
            return true;
    return prime(n, i + 1);
}
int main(){
    int n;
    cout << "Enter a number : " << endl;
    cin >> n;
    bool ans = prime(n);
    cout << "ANs is : " << ans << endl;
}