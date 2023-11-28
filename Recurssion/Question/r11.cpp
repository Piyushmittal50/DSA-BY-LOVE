#include<iostream>
using namespace std;

int bs(int arr[],int s,int e,int target){
    // base case
    if(s>e){
        return -1;
    }
    int mid = s + (e - s) / 2;

    if(arr[mid]==target){
            return mid;
    }
    else if(target<arr[mid]){
        int ans = bs(arr,s, mid - 1, target);
        return ans;
    }
    else{
        int ans = bs(arr,mid + 1, e, target);
        return ans;
    }
}
int main(){
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    int s = 0;
    int e = n - 1;
    int ele;
    cout << "Enter an Ele : " << endl;
    cin >> ele;
    int ans = bs(arr,s, e,ele);
    if(ans==-1){
        cout << "Ele is not present !" << endl;
    }
    else
        cout<<arr[ans]<< " Ele is present at " << ans << " index ! " << endl;
}