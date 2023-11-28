// Number of occurrence
#include<iostream>
using namespace std;
int Occurence(int arr[],int n,int number){
    int count = 0;
    for(int i=0;i<n;i++){
        if(number==arr[i]){
            count = count+1;
        }
    }
    return count;
}
int main(){
    int arr[] = {1,2,3,1,1,2,3,3,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int num;
    cout<<"Enter a number : "<<endl;
    cin>>num;
    int ans = Occurence(arr,size,num);

     cout<<"the Number of occurence of a given number is : "<<ans<<endl;
}