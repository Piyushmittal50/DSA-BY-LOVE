#include<iostream>
#include<vector>
using namespace std;
int singleNonDuplicate (vector<int> &arr){
    int n = arr.size();

    // edge cases
    if(n==1)
        return arr[0];
        if(arr[0]!=arr[1])
            return arr[0];
            if(arr[n-1]!=arr[n-2])
                return arr[n - 1];

            int start = 1;
            int end = n - 2;
            while(start<=end){
                int mid = start + (end - start) / 2;

                if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
                    return arr[mid];
                }

                // identify karna padeha ki ham ab kis haif mai hai
                if( (mid%2==1 && arr[mid-1]==arr[mid])|| (mid%2==0 && arr[mid]==arr[mid+1])){
                    start = mid + 1;
                }
                else
                    end = mid - 1;
            }
            return -1;
}
int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans = singleNonDuplicate(arr);
    cout << "The single element is: " << ans << "\n";
    return 0;
}