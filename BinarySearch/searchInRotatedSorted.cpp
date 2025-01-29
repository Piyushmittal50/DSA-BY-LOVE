// search an element in rotated sorted array
#include<iostream>
#include<vector>
using namespace std;
int findIndex(vector<int> arr,int n){
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    while (start < end){
        if (arr[mid + 1] < arr[mid]){
            start = mid + 1;
        }
        else{
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}

int find(vector<int> arr,int start,int end,int ele){
    int mid = start + (end - start) / 2;
    while (start <= end){
        if (arr[mid] == ele){
            return mid;
        }
        else if (arr[mid] <= ele){
            start = mid + 1;
        } 
        else{
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
  return -1;
}

int main(){
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int x = 9;
    // first find the min element in the array
    int minIndex = findIndex(arr, arr.size());
    cout << "minIndex is : " << minIndex << endl;
    
    // now search the target in both sorted array
    int ans01 = find(arr, 0, minIndex - 1,x);  // search in first half
    int ans02 = find(arr, minIndex, arr.size() -1, x);  // search in second half

    if(ans01 ==-1 && ans02 == -1){
        cout << "Element is not present in array!" << endl;
    }
    else if(ans01!=-1)
        cout << "element is present at index : " << ans01 << endl;
    else
        cout << "Element is present at index : " << ans02 << endl;

}