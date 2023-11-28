//  Reverse The Array in o(n) time
#include<bits/stdc++.h>
using namespace std;

void reversearray(int arr[],int start,int end){
    while(start<end){
     swap(arr[start],arr[end]);
     start++;
     end--;
    }
}
void printarray(int arr[],int s){
    for(int i=0;i<s;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){

int arr[] = {10,12,13,15,20,26};

int size = sizeof(arr)/sizeof(arr[0]);
cout<<"the orignal array is : "<<endl;
printarray(arr,size);
reversearray(arr,0,size-1);
cout<<"the reverse array is : "<<endl;
printarray(arr,size);

}


// Recursive C++ program to reverse an array
#include<bits/stdc++.h>
using namespace std;

void reversearray(int arr[],int start,int end){
    if(start>=end){
        return;
    }
        
     swap(arr[start],arr[end]);
     start++;
     end--;
     reversearray(arr,start,end);
    
}
void printarray(int arr[],int s){
    for(int i=0;i<s;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){

int arr[] = {10,12,13,15,20,26};

int size = sizeof(arr)/sizeof(arr[0]);
cout<<"the orignal array is : "<<endl;
printarray(arr,size);
reversearray(arr,0,size-1);
cout<<"the reverse array is : "<<endl;
printarray(arr,size);

}
