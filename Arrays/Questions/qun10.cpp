// Find the number that appears once, and the other numbers twice
#include<iostream>
using namespace std;
// Brute Force Approach
int getSingleElement(int arr[],int n){
     
     for(int i=0;i<n;i++){
        int count = 0;
        int num = arr[i];

        for(int j = 0;j<n;j++){
            if(arr[j]==num){
                count++;
            }
        }
        if(count==1){
            return num;
        }
     }
     return -1;
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = {4, 1, 2, 1, 2};
    int size = 5;
    cout<<"Input is -> "<<endl;
    print(arr,size);
    getSingleElement(arr,size);
    cout<<"Ans is -> "<<getSingleElement(arr,size)<<endl;
}

// better optimize by XOR

int XOR(int arr[],int n){
    int xor = 0;
    for(int i=0;i<n;i++){
        xor = xor^arr[0];
    }
    return xor;
}

// using hash array
int arryHashing(int arr[],int n){
    // first we have to find out the size of the array so that we can declare a hash
    int maxi arr[0];
    for(int i=0;i<n;i++){
        maxi = max(maxi,arr[i]);
    }

    // declare a hash
    vector<int> hash(maxi+1,0);

    // element of the array is now insert in the hash array 
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    //Find the single element and return the answer:
    for (int i = 0; i < n; i++) {
        if (hash[arr[i]] == 1)
            return arr[i];
    }
    // and here the arr[i] is the index of hash array
   return -1;
}