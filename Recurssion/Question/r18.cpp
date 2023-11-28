#include<iostream>
using namespace std;
void printSubArray(int arr[],int n){
    for (int i = 0; i < n;i++){
        for (int j = i; j < n;j++){
            for (int k = i; k <=j;k++){
                cout << arr[k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void subArray_utill(int arr[],int start,int end,int size){
// base case
if(end==size){
   return;
}
// 1 case solve
for (int i = start; i <= end;i++){
    cout << arr[i] << " ";
}
cout << endl;
// Rc
subArray_utill(arr, start, end + 1, size);
}

void subArray(int arr[],int size){
    for (int start = 0; start < size;start++){
        int end = start;
        subArray_utill(arr, start, end, size);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = 4;
    //cout << "All non-empty subArray is : " << endl;
    //printSubArray(arr, n);

    cout << "All non-empty subArray is : " << endl;
    subArray(arr, n);
}