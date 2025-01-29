// square root 
#include<iostream> // int => -10^9  to  +10^9
#include<math.h>  // long long int =>  -10^18 to  +10^18
using namespace std;
long long int find(int n){
    int start = 0;
    int end = n;

    while(start<=end){
        long long int mid = start + (end - start) / 2;
        if(mid*mid == n){
            return mid;
        }

        if(mid*mid < n){
            int ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }     
    }
    return -1;
}

double findpre(int number,int pre,double integer){
    int i = 0;
    double add = 0.1;
    while(i<pre){
        while(integer*integer<=number){
            integer += add;
        }
        if(integer*integer > number){
            integer -= add;
            add /= 10;
        }
        i++;
    }
    return integer;
}

double actualAns(int n,int count,int tempsol){
    double increment = 0.1;
    double ans = tempsol;

    for (int i = 0; i < count;i++){
        while(ans*ans<=n){
            ans += increment;
        }
        ans -= increment; // Step back to the last valid value
        increment /= 10;  // Decrease the step size
    }
    return ans;
}
int main(){
    int n = 37;
    int tempsol = find(n);
    cout << "Square root is : " << actualAns(n,5,tempsol)<< endl;
    cout << "Square root is : " << findpre(n, 5, tempsol) << endl;
}