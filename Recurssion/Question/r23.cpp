#include<iostream>
#include<vector>
using namespace std;
int maxHouse(vector<int> &houses,int i){
// base case
if(i>=houses.size())
    return 0;

// 1 case
int rob1 = houses[i] + maxHouse(houses, i + 2);
int rob2 = maxHouse(houses, i + 1);
return max(rob1, rob2);
}
int main(){
    vector<int> houses = {2,1,1,2};
    int ans = maxHouse(houses,0);
    cout << "Maximum houses theif can rob are : " << ans << endl;
}