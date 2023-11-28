#include<iostream>
using namespace std;

int findKey(int arr[],int num,int i=0,int size = 5){
    if(i>size)
        return -1;
    if(arr[i]==num)
        return i;

    return findKey(arr, num, i + 1);
}

int main(){
    int arr[] = {2, 4, 6, 7, 10};
    int size = 5;
    int Ele;
    cout << "Enter a Ele : " << endl;
    cin >> Ele;

    int key = findKey(arr, Ele);
    cout << Ele << " key is : " << key << endl;
}