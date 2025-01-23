#include<iostream>
#include<vector>
using namespace std;
int searchInsert(vector<int> &arr,int target){
    int start = 0;
    int end = arr.size() - 1;
    int minIndex = end;
    while(start<=end){
        int mid = (start + end) / 2;

        if(arr[mid]>=target){
            minIndex = mid;

            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return minIndex;
} 
int main()
{
    vector<int> arr = {1, 2, 4, 7,12,14,18};
    int x = 10;
    int ind = searchInsert(arr, x);
    cout << "The index is: " << ind << "\n";
    return 0;
}