#include<iostream>
#include<algorithm>
using namespace std;
// iterative method
int main(){
    string num1 = "11";
    string num2 = "123";
    string output = "";
    int n1 = num1.length()-1;
    int n2 = num2.length()-1;
    int carry = 0;
    while(n1>=0 && n2>=0){
        int c1 = num1[n1] - '0';
        int c2 = num2[n2] - '0';
        
        int Tsum = c1 + c2 + carry;
        if(Tsum>=10){
            int Tsum = Tsum % 10;
            carry = 1;
        }
        else{
            carry = 0;
        }
        char c = Tsum + '0';
        output = output + c;
        n1--;
        n2--;
    } 
    while(n1>=0){
        int d1 = num1[n1] - '0'; // char -> int
        int Tsum = d1 + carry;
        if(Tsum>=10){
            int Tsum = Tsum % 10;
            carry = 1;
        }
        else{
            carry = 0;
        }
        char c = Tsum + '0';  // int -> char
        output = output + c;
        n1--;
    }
    while(n2>=0){
        int d2 = num2[n2] - '0'; // char -> int
        int Tsum = d2 + carry;
        if(Tsum>=10){
            Tsum = Tsum % 10;
            carry = 1;
        }
        else{
            carry = 0;
        }
        char c = Tsum + '0';  // int -> char
        output = output + c;
        n2--;
    }

    if(carry==1){
        output = output + '1';
    }
    reverse(output.begin(), output.end());
    cout << "Sum is : " << output << endl;
}