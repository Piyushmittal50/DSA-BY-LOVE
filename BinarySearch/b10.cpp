#include<iostream>
#include<vector>
using namespace std;
int find(vector<int> &arr,int n){
    int start = 0;
    int end = n - 1;
    int index = -1;
    while(start<=end){
        int mid = start + (end - start) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;
        if(arr[prev]>=arr[mid] && arr[mid]<=arr[next]){
            index = mid;
        }

        if(arr[mid]<=arr[end]){
            end = mid - 1;
        }
        else if(arr[start]<=arr[mid]){
            start = mid + 1;
        }
    }
    return index;
}

// search an element in rotated sorted array
int firstHaif(vector<int> &arr,int start,int end,int ele){
while(start<=end){
    int mid = start + (end - start) / 2;
    if(arr[mid]==ele){
        return mid;
    }

    else if(arr[mid]<=ele)
        start = mid + 1;
    else
        end = mid - 1;
}
return -1;
}

int secondHaif(vector<int> &arr,int start,int end,int ele){
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == ele)
        {
            return mid;
        }

        else if (arr[mid] <= ele)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main(){
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = arr.size();
    int x = 9;
    int minIndex = find(arr, n);
    cout << "minIndex is : " << minIndex << endl;
    int ans01 = firstHaif(arr, 0, minIndex - 1,x);
    int ans02 = secondHaif(arr, minIndex, n - 1,x);
    if(ans01 ==-1 && ans02 == -1){
        cout << "Element is not present in array!" << endl;
    }
    else if(ans01!=-1)
        cout << "element is present at index : " << ans01 << endl;
    else
        cout << "Element is present at index : " << ans02 << endl;
}