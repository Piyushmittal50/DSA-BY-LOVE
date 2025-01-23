#include<iostream>
#include<vector>
using namespace std;
int findFirst(vector<int> &arr,int x){
    int start = 0;
    int end = arr.size() - 1;
    int first = 0;
 
    while(start<=end){
        int mid = (start + end) / 2;

        if(arr[mid]==x){
            first = mid;

            end = mid - 1;
        }

        else if(arr[mid]<x){
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return first;
}
int findLast(vector<int> &arr,int x){
    int start = 0;
    int end = arr.size() - 1;
    int last = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == x)
        {
            last = mid;

            start = mid + 1;
        }

        else if (arr[mid] < x)
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return last;
}
pair<int,int> findOccur(vector<int> &arr,int x){
  
    int a = findFirst(arr, x);
    int b = findLast(arr, x);

    return make_pair(a, b);
}
int main(){
    vector<int> arr = {2, 2, 3, 3, 3, 3, 3};
    int x = 3;
    cout << "First : " << findFirst(arr, x) << endl;
    cout << "second : " << findLast(arr, x) << endl;
    pair<int,int> ans = findOccur(arr, x);
    int count = ans.second - ans.first + 1;
    cout << "Ans is : " << count << endl;
}