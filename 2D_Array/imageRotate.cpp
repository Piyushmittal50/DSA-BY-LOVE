// Rotate Image by 90 degree
#include<bits/stdc++.h>
using namespace std;
// Brute approach 
vector<vector<int>> rotate(vector<vector<int>> & matrix) {
    int n = matrix.size();
    vector<vector<int>>rotated(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        rotated[j][n-1-i] = matrix[i][j];
    }
    }
    return rotated;
}
// optimal approach       --- Time O(N*N)    --- Space O(1)
void rotateImage(vector<vector<int>> &matrix){
    // int m = arr.size();
    // int n = arr[0].size();

    int n = matrix.size();
    // transposing the matrix
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            matrix[i][j] = matrix[j][i];
        }
    }
    // reversing each row of the matrix
    for (int i = 0; i < n; i++){
        int left = 0;
        int right = n - 1;
        while (left < right){
            swap(matrix[i][left], matrix[i][right]);
            left++;
            right--;
        }
    }
}
void print(vector<vector<int>>& matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    vector<vector<int>> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    cout<<"Input Matrix is -> "<<endl;
    print(arr);

    vector<vector< int >> rotated = rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < rotated.size(); i++) {
    for (int j = 0; j < rotated[0].size(); j++) {
        cout << rotated[i][j] << " ";
    }
    cout <<endl;
    }
    cout<<endl;
}

