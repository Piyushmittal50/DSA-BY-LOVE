//#include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
   unordered_map<string,int> map_name;    // string is the key 
                                          // int is the inter value
   
   // insert element into unordered_map
   map_name["one"] = 10;
   map_name["two"] = 20;
   map_name["three"] = 30;

   // assigning values of map 
  int first = map_name["one"];
  int second = map_name["two"];
  int third =  map_name["three"];

  cout<<"first : " <<" "<<first<<endl;
  cout<<"second : "<<" "<<second<<endl;
  cout<<"third : "<<" "<<third<<endl;

  for(auto x : map_name){
    cout<<x.first<<" "<<x.second<<endl;
  }
}