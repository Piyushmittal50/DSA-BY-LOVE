#include<iostream>
using namespace std;
int getFlor(int arr[],int n,int target){
    int start = 0;
    int end = n - 1;
    int flor;
    while(start<=end){
        int mid = (start + end) / 2;

        if(arr[mid]<=target){
            flor = arr[mid];

           
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return flor;
}
int getCeil(int arr[],int n,int target){
    int start = 0;
    int end = n - 1;
    int ceil;
    while(start<=end){
        int mid = (start + end) / 2;

        if(arr[mid]>=target){
            ceil = arr[mid];

            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return ceil;
}
pair<int, int> getFloorAndCeil(int arr[],int n,int target){
    int flor = getFlor(arr, n, target);
    int ceil = getCeil(arr, n,target);
    pair<int,int> ans = make_pair(flor, ceil);
    return ans;
} 
int main()
{
    int arr[] = {3, 4, 4, 7, 8, 10};
    int n = 6, x = 5;
    pair<int, int> ans = getFloorAndCeil(arr, n, x);
    cout << "The floor and ceil are: " << ans.first
         << " " << ans.second << endl;
    return 0;
}