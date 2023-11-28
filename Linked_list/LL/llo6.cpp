#include<iostream>
#include<unordered_set>  // set store unique keys
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
bool findLoop(node* &head){
    if(head==NULL || head->next==NULL){
        return false;
    }
    // using two pointer
    node* slow = head;
    node* fast = head;

    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(slow==fast){
            return true;
        }
    }
    return false;
}

// using unordered_set
bool findloop(node* &head){
    unordered_set<node*> visited;
    node* curr = head;
    while(curr){
        if(visited.find(curr)!=visited.end()){
            return true;
        }
        visited.insert(curr);
        curr = curr->next;
    }
    return false;
}
int main(){
     node* head = new node(10);
    node* second = new node(20);
    node* third = new node(30);
    node* fourth = new node(40);
    node* fifth = new node(50);
    node* sixth = new node(60);
    node* seven = new node(70);
    node* eight = new node(80);
    node* nine = new node(90);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seven;
    seven->next = eight;
    eight->next = nine;
    nine->next = NULL;

    if(findloop(head)){
        cout<<"LOOp is present "<<endl;
    }
    else cout<<"LOOP is not present"<<endl;
}