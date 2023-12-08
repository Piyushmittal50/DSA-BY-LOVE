// Peak element in Array
#include<iostream>
#include<vector>
using namespace std;
int search(vector<int> &arr,int n){
  // edge cases
  if(n==0)
      return -1;
  if(arr[0]>arr[1])
      return arr[0];
  if(arr[n-1]>arr[n-2])
      return arr[n - 1];

  int start = 1;
  int end = n - 2;
  while(start<=end){
      int mid = start + (end - start) / 2;

      if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
          return arr[mid];
      }
      if(arr[mid-1]<arr[mid])
          start = mid + 1;
      else
          end = mid - 1;
  }
  return -1;
}
int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int x = 6;
    int size = arr.size();
    int ans = search(arr, size);
    cout << "Peak element  is : " << ans << endl;
}