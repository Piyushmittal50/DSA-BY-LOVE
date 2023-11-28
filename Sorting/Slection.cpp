#include <bits/stdc++.h>
using namespace std;
void slection(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }

            swap(arr[min], arr[i]);
        }
    }
}
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {64, 12, 25, 22, 11};
    int n = 5;
    slection(arr, n);
    cout << "The Sorted array is : " << endl;
    printarray(arr, n);
}