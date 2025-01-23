#include<iostream>
#include<vector>
using namespace std;
int LowerBound(vector<int> &arr,int target){  // lower index is always == arr[mid]>=target
    int start = 0;
    int end = arr.size() - 1;
    int minIndex;
    while(start<=end){
        int mid = (start + end) / 2;
        if (arr[mid] >= target)
        {
             minIndex = mid;

            // look at the left side for smaller index
            end = mid - 1;
        }
        else // look on the right side          
        start = mid + 1;        
    }

    return minIndex;
}

int UpperBound(vector<int> &arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    int maxIndex;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] > target)
        {
            maxIndex = mid;

            end = mid - 1;
        }
        else 
            
        start = mid + 1;
    }

    return maxIndex;
}

int main(){
    vector<int> arr = {3, 3, 4, 4, 9, 12, 16, 17};
    int target;
    cout << "Enter a number : " << endl;
    cin >> target;
    int ans = LowerBound(arr, target);
    cout << "Lower bound is : " << ans << endl;

    int ans01 = UpperBound(arr, target);
    cout << "Upper bound is : " << ans01 << endl;
}