// Search in a sorted 2D matrix

#include<iostream>
#include<vector>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix,int target){
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==target){
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int n = matrix.size();
    int m = matrix[0].size();
    cout<<"Input is -> "<<endl;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    searchMatrix(matrix,8) == true ? cout<<"true\n" : cout<<"false\n";
}