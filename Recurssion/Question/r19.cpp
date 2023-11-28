#include<iostream>
#include<vector>
using namespace std;
void maxProfitFinder(vector<int>& prices,int i,int& maxProfit,int& minPrice ){
// base case
if(i==prices.size())
    return;

// 1 case solve
if(prices[i]<minPrice)
    minPrice = prices[i];

int todayprofit = prices[i] - minPrice;
if(todayprofit>maxProfit)
    maxProfit = todayprofit;
// Recursion
maxProfitFinder(prices, i + 1, maxProfit, minPrice);
}
int maxProfit(vector<int>& prices){
    int maxProfit = INT_MIN;
    int minPrice = INT_MAX;

    maxProfitFinder(prices, 0, maxProfit, minPrice);
    return maxProfit;
}
int main(){
    vector<int> prices = {7, 1, 5, 6, 3, 4};
    cout << "Maximum profit is : " << maxProfit(prices) << endl;
}