#include<iostream>
#include<vector>
using namespace std;
vector<int> spiral(vector<vector<int>> matrix){
    int m = matrix.size();  // number of rows
    int n = matrix[0].size();  // number of col
    int top = 0;
    int bottom = m - 1;
    int left = 0;
    int right = n - 1;
    vector<int> ans;
    int total_element = m * n;
    int count = 0;
    while(count<total_element){
        // move from left to right
        for (int i = left; i <= right && count<total_element;i++){
            ans.push_back(matrix[top][i]);
            count++;
        }
        top++;

        // move from top to bottom
        for (int i = top; i <= bottom && count < total_element; i++)
        {
            ans.push_back(matrix[i][right]);
            count++;
        }
        right--;

        // move from right to left
        for (int i = right; i >= left && count < total_element; i--)
        {
            ans.push_back(matrix[bottom][i]);
            count++;
        }
        bottom--;

        // move from bottom to top
        for (int i = bottom; i >= top && count < total_element; i--)
        {
            ans.push_back(matrix[i][left]);
            count++;
        }
        left++;
    }
    return ans;
}
int main(){
    vector<vector<int>> mat{{1, 2, 3, 4},
                            {5, 6, 7, 8},
                            {9, 10, 11, 12},
                            {13, 14, 15, 16}};
    vector<int> ans = spiral(mat);
    for(auto c : ans){
        cout << c << " ";
    }
    cout << endl;
}