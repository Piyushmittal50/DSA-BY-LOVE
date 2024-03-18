// maximum concecutive ones's
#include<iostream>
using namespace std;
int maxOnes(int arr[],int n){
    int store = 0;
    int maxi = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            store++;
        }
        else{
            store = 0;
        }
        maxi = max(maxi,store);
    }
    return maxi;
}

int main(){
    int arr[] = {1, 1, 0, 1, 1, 1};
    int size = 6;
    cout<<"Maximum 1's -> "<<maxOnes(arr,size);
}