// Using a max variable 
#include<bits/stdc++.h>
using namespace std;

int largestelement(int arr[],int s){
   int max = arr[0];
   int i=0;
   for(i=0;i<s;i++){
   if(arr[i]>max)
    max = arr[i];
   }
   return max;
}
int main(){
  int arr[] = {10,12,11,45,34,19,67};
  int size = sizeof(arr)/sizeof(arr[0]);
  cout<<"Given Array is : "<<endl;
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  cout<<"Largest element is : "<<largestelement(arr,size)<<endl;
  
}


// using sorting approach
#include<bits/stdc++.h>
using namespace std;
int largestelement(int arr[],int s){
    sort(arr,arr+s);

    return arr[s-1];
}

int main(){
    int arr[] = {12,14,9,145,12,10,30};
    int size = sizeof(arr)/sizeof(arr[0]);
    int largest=largestelement(arr,size);
    cout<<"largest element is  : "<<largest<<endl;
}