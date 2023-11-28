#include<iostream>
using namespace std;
bool print(int arr[],int n,int i){
    if(i==n-1){
        return true;
    }

    if(arr[i+1]<arr[i]){
        return false;
    }
   
   return  print(arr, n, i + 1);
}
int main(){
    int arr[] = {10, 20, 25, 55, 40};
    int n = 5;
    int i = 0;
    bool ans = print(arr, n,i);
    if(ans){    
        cout << "Array is sorted" << endl;
    }
    else
        cout << "Array is not sorted" << endl;
}