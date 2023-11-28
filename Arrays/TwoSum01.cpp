#include<iostream>
#include<vector>
#include<unordered_map>
std::vector<int> twosum(std::vector<int> &arr,int target){
     std::unordered_map<int,int> number;
     for(int i=0;i<arr.size();i++){
        int num  = arr[i];
        int temp = target-num;
        if(number.find(temp)!=number.end()){
            return {number[temp],i};
        }
        number[temp] = i;
     }
     return {-1,-1};
}
int main(){

std::vector<int> arr={2,7,11,15};
int target = 9;
std::vector<int> result = twosum(arr,target);
std::cout<<"the indicies are : "<<result[0]<<" "<<result[1];

}