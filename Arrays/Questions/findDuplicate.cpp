#include<bits/stdc++.h>
using namespace std;
// using cycle detection
int findDuplicate(int arr[],int n){
    int slow = arr[0];
    int fast = arr[0];
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    fast = arr[0];
    while(slow!=fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
int main(){
    int arr[] = {1, 3, 4, 2, 2, 5, 6};
    int n = 7;
    int dupli = findDuplicate(arr, n);
    cout << "Duplicate value is : " << dupli << endl;
}