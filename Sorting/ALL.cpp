#include<bits/stdc++.h>
using namespace std;
void bubble(vector<int> &arr){
    // compare two element
  for(int i=0;i<arr.size()-1;i++){
      for(int j=0;j<arr.size()-i-1;j++){
          if(arr[j]>arr[j+1]){
              swap(arr[j],arr[j+1]);
          }
      }
  }
}
void selection(vector<int> &arr){
    for(int i=0;i<arr.size()-1;i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[i]){
                swap(arr[j],arr[i]);
            }
        }
        
    }
}
void insertion(vector<int> &arr){
    for(int i=0;i<=arr.size()-1;i++){
        int j = i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}
int main(){
    vector<int> arr = {56,10,2,34,45,23,1,11};
    cout<<"array is : "<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //bubble(arr);
    cout<<"sorting using bubble is : "<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //selection(arr);
    cout<<"sorting using selection is : "<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    insertion(arr);
     cout<<"sorting using insertion is : "<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}