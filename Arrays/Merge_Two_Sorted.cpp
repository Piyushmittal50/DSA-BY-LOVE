#include<iostream>
using namespace std;
void merge(int arr[],int s,int e){
    int mid = (s+e)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;
    int* first = new int[len1];
    int* second = new int[len2];

    // copy karna
    
    for(int i=0;i<len1;i++){
       first[i] = arr[s+i];   // copy from actual arr into first
    }
    for(int j=0;j<len2;j++){
        second[j] = arr[mid+j+1];
    }

    // and now merge

    int firstIndex = 0;
    int secondIndex = 0;
    int mainIndex = s;

    while(firstIndex < len1 && secondIndex < len2){
    if(first[firstIndex]<=second[secondIndex]){
     arr[mainIndex] = first[firstIndex];
     firstIndex++;
    }
    else{
     arr[mainIndex] = second[secondIndex];
     secondIndex++;
    }
    mainIndex++;
 }

 // if first and second is not equal to each other
    while(firstIndex < len1){
        arr[mainIndex] = first[firstIndex];
        mainIndex++;
        firstIndex++;
    }

    while(secondIndex < len2){
        arr[mainIndex] = second[secondIndex];
        mainIndex++;
        secondIndex++;
    }
}

void mergeSorted(int arr[],int s,int e){
    // base case

    if(s>=e){
        return;
    }

    // break karo  -> A
    int mid = (s+e)/2;

    // left part sort kardo recurrsion  -> B
    mergeSorted(arr,s,mid);

    // right part sort kardo   -> C
    mergeSorted(arr,mid+1,e);
    
    // now merge 2 sorted array   -> D
    merge(arr,s,e);
}
int main(){
   int arr[] = {2,8,7,3,9,4};
   int n = 6;
   int s = 0;
   int e = n-1;
   mergeSorted(arr,s,e);
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
   }
   cout<<endl;
}