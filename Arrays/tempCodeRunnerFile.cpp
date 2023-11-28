#include<iostream>
using namespace std;
int partition(int* arr,int s,int e){

  //step 1-> choose pivot element 
  int pivotIndex = s;
  int pivotEle = arr[s];

  //step 2-> find right position of pivot ele and place it
  int count = 0;
  for(int i=s+1;i<e;i++){
    if(arr[i]<=pivotEle){
        count++;
    }
  }
  // now we have right index position
  int rightIndex = s+count;
  swap(arr[pivotIndex],arr[rightIndex]);
  pivotIndex = rightIndex;

  // step 3-> left me chote and right me bade
int i = s;
int j = e;
 while(i<pivotIndex && j>pivotIndex){
    while(arr[i]<pivotEle){
        i++;
    }
    while(arr[j]>pivotEle){
        j--;
    }

    // lekin agar aesa hua jisme left mai kuch bade bade element mile , 
    // and right mai kuch chote element mile
    // then we have to swap it
    if(i<pivotIndex && j>pivotIndex){
        swap(arr[i],arr[j]);
    }
 }

 return pivotIndex;

}
void quickSort(int* arr,int s,int e){
  // base case
  if(s>=e){
    return;
  }

  // partition logic
   int p = partition(arr,s,e);   // p = pivot element index

  // recursive calls
   
     // left
     quickSort(arr,s,p-1);   // pivot index ko chorkar because pivot index element is already sorted

     // right
     quickSort(arr,p+1,e);
}
int main(){
    int arr[] = {8,1,3,4,20,50,30};

    int n = 7;
    int s = 0;
    int e = n-1;
    quickSort(arr,s,e);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;  
}