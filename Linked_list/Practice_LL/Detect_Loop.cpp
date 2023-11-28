#include<iostream>  
#include<unordered_set>
using namespace std;
class node{
     public:
     int data;
    node* next;
    node(){
        this->data = 0;
        this->next  = NULL;
    }
    node(int data){
        this->data = data;
        this->next = NULL; 
    }
};

bool findloop(node* &head){  // basic approach using unordered_set || unordered_map
    node* curr = head;
    unordered_set<node*> visited;
    while(curr!=NULL){
        if(visited.find(curr)!=visited.end()){
            return true;
        }
        visited.insert(curr);
        curr = curr->next;
    }
    return false;
}
bool find_loop(node* &head){  // using Floyd's Cycle Detection Algorithm || tortoise and hare approach || two pointer approach
    if(head==NULL){
        return false;
    }
    node* fast = head;
    node* slow = head;
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
    nine->next = fifth;
    if(findloop(head)==true){
      cout<<"LOOP IS PRESENT"<<endl;
    }
    else{
        cout<<"LOOP is not present"<<endl;
    }
     if(find_loop(head)==true){
      cout<<"LOOP IS PRESENT"<<endl;
    }
    else{
        cout<<"LOOP is not present"<<endl;
    }
}