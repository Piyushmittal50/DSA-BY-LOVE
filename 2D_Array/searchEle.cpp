#include<iostream>
#include<vector>
using namespace std;

// each row of matrix par search karege
bool searchTarget(vector<int> arr,int x){
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;
    while(start<=end){
        if(arr[mid]==x){
            return true;
        }
        else if(arr[mid]<x){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return false;
}

bool searchMatrix(vector<vector<int>> matrix,int target){
    for (int i = 0; i < matrix.size();i++){
        if(searchTarget(matrix[i],target)){
            return true;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    searchMatrix(matrix, -1) == true ? cout << "Element is found" << endl
    : cout << "Element is not found"<<endl;
}