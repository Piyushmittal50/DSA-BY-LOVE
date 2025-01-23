// // Find the missing number in an array
#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> arr){
    int n = arr.size();
    vector<bool> present(n+1,false);
    for(int i=0;i<n;i++){
        present[arr[i]] = true;
    }

    for (int i = 1; i <= n + 1;i++){
        if(!present[i]){
            return i;
        }
    }
    return -1;
}
int another(vector<int> arr){
    int n = arr.size();
    int totalsum = 0;
    for (int i = 1; i <= n + 1;i++){
        totalsum += i;
    }
        int actualsum = 0;
    for (int i = 0; i < n;i++){
        actualsum += arr[i];
    }
    return totalsum - actualsum;
}
int main(){
    vector<int> a = {1,2,4,5};
    int ans = another(a);
    cout<<"The Missing Number is : "<<ans<<endl;
    return 0;
}