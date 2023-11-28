#include <iostream>
using namespace std;
int power(int n)
{
    // base case
    if (n == 0)
        return 1;

    int choti = power(n - 1);
    int badi = 2 * choti;
    return badi;
}
int main()
{
    int n;
    cout << "Enter a number : " << endl;
    cin >> n;
    int ans = power(n);
    cout << "ans is : " << ans << endl;
}