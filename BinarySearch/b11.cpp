#include<iostream>// nearly sorted array
#include<vector>
using namespace std;
int nearly(vector<int> &arr,int x,int start,int end){
while(start<=end){
    int mid = start + (end - start) / 2;
    if (arr[mid] == x)
        return mid;
        if(arr[mid-1]==x)
            return mid - 1;
            if(arr[mid+1]==x)
                return mid + 1;

                else if(arr[mid]<x)
                    start = mid + 2;

                    else
                        end = mid - 2;
}

return -1;
}
int main(){
    vector<int> arr = {3, 2, 10, 4, 40};
    int x = 4;
    int n = arr.size();
    int ans = nearly(arr, x, 0, n - 1);
    cout << "index is : " << ans << endl;
}