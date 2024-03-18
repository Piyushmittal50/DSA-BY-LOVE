// Check if an Array is Sorted
#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
bool sorted(vector<int> arr,int n){
    bool temp = true;
    int i= 0;
    while(i<n-1){
        if(arr[i]<=arr[i+1]){
            i++;
        }
        else{
            temp = false;
            break;
        }
    }
   return temp;
}
int main(){
    vector<int> arr = {1,1,9,5,6,7};
    int size = arr.size();

    cout<<"input is -> "<<endl;
    print(arr,size);

    bool ans = sorted(arr,size);
    if(ans)
    cout<<"arr is sorted"<<endl;
    else
    cout<<"arr is not sorted"<<endl;
}