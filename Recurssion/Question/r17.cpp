#include<iostream>
using namespace std;
void removeOccurance(string& s,string part){
    int found = s.find(part);
    if(found != string::npos){
      // part string has been located
      // so remove it now
      string left_part = s.substr(0, found);  // substr(starting point,number of elements)
      string right_part = s.substr(found + part.size(), s.size());
      s = left_part + right_part;
      removeOccurance(s, part);
    }
    else{   
      // base case
      // all the part has been removed from s.
      return;
    }
}
string occu(string& s,string part){
    removeOccurance(s, part);
    return s;
}
int main(){
    string input = "pababccp";
    string part = "abc";
    string ans = occu(input, part);
    cout << "After Removing all Occur : " << ans << endl;
}