#include<iostream>
using namespace std;
void multiply(int first[2][2],int second[2][2],int n){
    int c[2][2] = {0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          
          for(int k=0;k<n;k++){
            c[i][j] += first[i][k]*second[k][j]; 
          }
        }
    }
    cout<<"printing....."<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
   int arr1[2][2] = {{1,2},{3,4}};
   int arr2[2][2] = {{1,2},{3,4}};
   int n = 2;
   multiply(arr1,arr2,n);
}