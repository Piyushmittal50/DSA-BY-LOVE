// check the given array that array is sorted or not
// Time Complexity is : O(N) due to single traverse
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {5, 4, 7, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    bool isSorted = true;
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            isSorted = false;
            break;
        }
    }
    if (isSorted)
    {
        cout << "Array is sorted";
    }
    else
    {
        cout << "Array is not sorted";
    }
    return 0;
}



