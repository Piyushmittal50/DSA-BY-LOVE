// second largest and smallest ele
#include<iostream>
using namespace std;
pair<int,int> second_large_small(int arr[],int n){
    int small = INT_MAX;
    int large = INT_MIN;
    for(int i=0;i<n;i++){
         small = min(small,arr[i]);
         large = max(large,arr[i]);
    }
    int second_large = INT_MIN;
    int second_small = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]!=small && arr[i]<second_small){
        second_small = arr[i];
        }

        if(arr[i]!=large && arr[i]>second_large){
            second_large = arr[i];
        }
    }
    return make_pair(second_small,second_large);
}
int main()
{
    int arr[] = {1,4,5,10,9,12,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    pair<int,int> ans  = second_large_small(arr,size);
    cout<<"Second Smallest Ele -> "<<ans.first<<endl;
    cout<<"Second Largest Ele -> "<<ans.second<<endl;
}