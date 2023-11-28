// Union of Two Sorted Arrays
// approach 1  :  Using Set
#include<bits/stdc++.h>
using namespace std;
vector <int> FindUnion(int arr1[],int arr2[],int n1,int n2){
    set <int> s;
    vector <int> Union;
    for(int i=0;i<n1;i++){
        s.insert(arr1[i]);
    }
    for(int i=0;i<n2;i++){
        s.insert(arr2[i]);
    }
    for(auto & it: s)
    Union.push_back(it);
    return Union;
}
int main(){
    int arr1[] = {1,2,4,6,7,9};
    int arr2[] = {3,4,5,6,7,8};

    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    vector <int> Union = FindUnion(arr1,arr2,n1,n2);
    cout<<"Union of arr1 and arr2 is "<<endl;
    for(auto & val:Union)
    cout<<val<<" ";
    return 0;
}

// using unordered_map 
#include<bits/stdc++.h>
using namespace std;
vector <int> FindUnion(int arr1[],int arr2[],int n1,int n2){
    map <int,int> freq;
    vector <int> Union;
    for(int i=0;i<n1;i++){
        freq[arr1[i]]++;
    } 
    for(int i=0;i<n2;i++){
        freq[arr2[i]]++;
    }
    for(auto & it: freq){
        Union.push_back(it.first);
    }
    return Union;
}

int main(){
    int arr1[] = {1,2,4,6,7,9};
    int arr2[] = {3,4,5,6,7,8};
    
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    
    vector <int> Union = FindUnion(arr1,arr2,n1,n2);
    cout<<"Union of arr1 and arr2 is "<<endl;
    for(auto & val: Union)
    cout<<val<<" ";
    return 0;
}