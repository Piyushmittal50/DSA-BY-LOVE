// left & right rotate by K elements
#include<iostream>
using namespace std;
void left_rotate(int arr[],int n,int left){
    // copy the first k element
    int temp[left];
    for(int i=0;i<left;i++){
        temp[i] = arr[i];
    }
    // now after the k elements first rearrange them
     int count = 0;
     for(int i = left ;i <n;i++){
        arr[count] = arr[i];
        count++;
     }

    for(int i = 0; i<left;i++){
         arr[count] = temp[i];
         count++;
     }
}
void Right_rotate(int a[],int s,int right){
      // now first copy k element
      int temp[right];
      for(int i=0;i<right;i++){
        temp[i] = a[s-right+i];
      }
      
      // now shift to right position
       int count = s - 1;
    for (int i = s - right - 1; i >= 0; i--) {
        a[count] = a[i];
        count--;
    }
      for(int i = 0;i<right;i++){
        a[i] = temp[i];
      }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int a[] = {1,2,35,60,70,45};
    int size = 7;
    int s = 6;
    int left= 2;
    int right = 3;
    cout<<"Left Rotate by 2 Ele : "<<endl;
    left_rotate(arr,size,left);
    print(arr,size);
    cout<<"Right Rotate by 2 Ele : "<<endl;
    Right_rotate(a,s,right);
    print(a,s);
}

