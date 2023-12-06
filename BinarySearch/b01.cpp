#include<iostream> 
#include<vector>
using namespace std;
int binarySearch(vector<int> &arr,int &target,int start,int end){
    
        // base case
        if(start>end){
            return -1;
        }
        int mid = ( start + end ) / 2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            int ans = binarySearch(arr, target, mid + 1, arr.size()-1);
            return ans;
        }
        else{
            int ans = binarySearch(arr, target, 0, mid - 1);
            return ans;
        }
}
int Search(vector<int> &arr,int target){
    return binarySearch(arr, target, 0, arr.size()-1);
}
int main(){
    vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 17};
    int target;
    cout << "Enter a number : " << endl;
    cin >> target;
    if(Search(arr,target)!=-1){
        cout << "Element found at index : " << Search(arr, target) << endl;
    }
    else
        cout << "Ele is not present" << endl;
}