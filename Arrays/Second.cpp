//Find Second Smallest and Second Largest Element in an array
// Time Complexity is : O(NlogN) 
// in c++ sort function complexity is O(NlogN)
#include<bits/stdc++.h>
using namespace std;
void secondarray(int arr[],int size){
    
    if(size==0 || size==1){
        cout<<"No Second Smallest Element and No Second Largest Element";
    }

    int small;
    int large;
    sort(arr,arr+size);
    cout<<"Second Smallest Element is : "<<arr[1]<<endl;
    cout<<"Second Smallest Element is : "<<arr[size-2]<<endl;
}
int main(){
int arr[] = {1,2,4,7,7,5};
 int size = sizeof(arr)/sizeof(arr[0]);

 secondarray(arr,size);
  return 0;
}

// Second Largest Element in an Array without sorting
// Linear search : O(N)

#include<bits/stdc++.h>
using namespace std;

void getelement(int arr[],int s)
{
    if(s==0 || s==1){
        cout<<"No Second Largest And Smallest Element"<<endl;
    }
 int second_largest=INT_MIN,large=INT_MIN;
   int second_small=INT_MAX,small=INT_MAX;

   int i;
   for(i=0;i<s;i++){
    small = min(small,arr[i]);
    large = max(large,arr[i]);
   }
    for(i=0;i<s;i++){
       if(arr[i]<second_small && arr[i]!=small)
        second_small = arr[i];
        if(arr[i]>second_largest && arr[i]!=large)
         second_largest = arr[i];
    }

    cout<<"Second largest element is : "<<second_largest<<endl;
    cout<<"Second smallest element is : "<<second_small<<endl;
}
void printarray(int arr[],int s){
    int i;
    for(i=0;i<s;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){

   int arr[] = {1,2,4,7,7,5};
   int size = sizeof(arr)/sizeof(arr[0]);
  
   cout<<"given array is : "<<endl;
   printarray(arr,size);
   getelement(arr,size);
}
