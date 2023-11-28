#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};
vector<int> nextLargestNode(node* &head){
    vector<int> LL;
    while(head){
        LL.push_back(head->data);
        head = head->next;
    }

    stack<int> s;
    vector<int> ans(LL.size());

    
}
int main(){
   node* first = new node(2);
   node* second = new node(7);
   node* third = new node(4);
   node* fourth = new node(3);
   node* fifth = new node(5);

   first->next = second;
   second->next = third;
   third->next = fourth;
   fourth->next = fifth;
   fifth->next = NULL;
   nextLargestNode(first);
}