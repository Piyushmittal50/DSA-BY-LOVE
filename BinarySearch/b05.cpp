#include<iostream>
#include<vector>
using namespace std;
int Last_Occurence (vector<int> &arr,int target){
    int start = 0;
    int end = arr.size() - 1;
    int posAns;
    while(start<=end){
        int mid = (start + end) / 2;

        if(arr[mid] == target){
            posAns = mid;

            start = mid + 1;
        }
        else if(arr[mid]<target){
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return posAns;
}
int main()
{
    vector<int> arr = {3, 4, 13, 13, 13, 20, 40};
    int target;
    cout << "Enter a number : " << endl;
    cin >> target;
    int ans = Last_Occurence(arr, target);
    if(ans!=-1){
        cout << "Last occurence is : " << ans << endl;
    }
    else
        cout << "Ele is not present" << endl;
}