#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<int,bool> map_name;
    // value assign to map_name

    map_name[10] = "true";
    map_name[20] = "false";
    map_name[30] = "true";

    // search element in unordered_map using the key

    if(map_name.find(20)==map_name.end()){    // find() is used to find a element in the unsorted_map 
                                              // it takes an key as a paramete
        cout<<"element is not present "  <<endl;                           
                                                 // end() basically goes from start pointer to end pointer 
    }
    else{
        cout<<"element is present : "<<map_name[20]<<endl;
    }


}                                            