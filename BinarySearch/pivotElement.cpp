// pivot element is the smallest element in an rotated sorted array
//point in array at which the array has benn rotated] && number of times array has been rotated
#include<vector>
#include <iostream>
using namespace std;
int search(vector<int> arr,int n){
    int start = 0;
    int end = n - 1;

    while(start<=end){
        int mid = start + (end-start) / 2;
        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;

        if(arr[prev]>=arr[mid] && arr[next]>=arr[mid]){
            return mid;
        }

        if (arr[mid] <= arr[end])
        {
            end = mid - 1;
        }
        else if (arr[start]<=arr[mid]){ // unsorted array
            start = mid + 1;
        }
    }
    // default values , if arr is not rotated 
    return arr[0];
}

int findPivot(vector<int> arr){
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;
    while(start<end){
        if(arr[mid+1]<arr[mid]){
            start = mid + 1;
        }
        else{
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}
int main()
{
    vector<int> arr = {10, 11, 15 ,18, 2, 5, 6,8};  // Rotated sorted array
    int ans = search(arr, arr.size());
    cout << "number of times array has been rotated : " << ans << endl;
    cout << "The minElement is: " << arr[ans] << "\n";
    

    int pivot = findPivot(arr);
    cout << "Pivot element is : " << arr[pivot] << endl;
}