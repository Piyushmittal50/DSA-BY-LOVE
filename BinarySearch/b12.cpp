// square root 
#include<iostream> // int => -10^9  to  +10^9
#include<math.h>  // long long int =>  -10^18 to  +10^18
using namespace std;
long long int find(int n){
    int start = 0;
    int end = n;
    if(n==0)
        return 0;
        if(n==1)
            return 1;
    while(start<=end){
        long long int mid = start + (end - start) / 2;
        if(mid*mid == n){
            return mid;
        }

        if(mid*mid < n){
            int ans = mid;

            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return -1;
}
double actualAns(int n,int count,int tempsol){
    double factor = 1;
    double ans = tempsol;
    for (int i = 0; i < count;i++){
        factor = factor / 10;

        for (double j = ans; j * j < n; j=j+factor){
            ans = j;
        }
    }
    return ans;
}
int main(){
    int n = 37;
    int tempsol = find(n);
    cout << "Square root is : " << actualAns(n,5,tempsol)<< endl;
}