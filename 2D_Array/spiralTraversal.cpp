// Spiral Traversal of Matrix
#include<iostream>  
#include<vector>
using namespace std;
vector<int> SpiralTraversal(vector<vector<int>>& matrix){
    vector<int> ans;
    int n = matrix.size();
    int m = matrix[0].size();
    int total_ele = n*m;

    int startingRow = 0;
    int endingCol = m-1;
    int endingRow = n-1;
    int startingCol = 0;

    int count = 0;
    while(count<total_ele){
        // printing startingRow
       for(int i=startingCol ;i<=endingCol && count<total_ele ;i++){
        ans.push_back(matrix[startingRow][i]);
        count++;
       }
       startingRow++;
       // printing endingCol
       for(int i=startingRow;i<=endingRow && count<total_ele;i++){
        ans.push_back(matrix[i][endingCol]);
        count++;
       }
       endingCol--;
       // printing endingRow
       for(int i=endingCol;i>=startingCol && count<total_ele;i--){
        ans.push_back(matrix[endingRow][i]);
        count++;
       }
       endingRow--;
       // printing startingCol
       for(int i=endingRow;i>=startingRow && count<total_ele;i--){
        ans.push_back(matrix[i][startingCol]); 
        count++;
       }
       startingCol++;
    }
    return ans;
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
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    cout<<"Input Matrix is -> "<<endl;
    print(matrix);
    vector<int> ans = SpiralTraversal(matrix);
    cout<<"Spiral Matrix is -> "<<endl;
    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
}