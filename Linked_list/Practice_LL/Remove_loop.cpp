#include<iostream>
#include<unordered_set>
using namespace std;
class node{
   public:
   int data;
   node* next;
   node(){
    this->data = 0;
    this->next = NULL;
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

node* removeloop(node* &head){
    if(head==NULL){
        return NULL;
    }
    node* slow = head;
    node* fast = head;
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(slow==fast){
            fast = head;
            break;
        }
    }
    if(fast==NULL){
        return NULL;
    }
    node* prev = fast;
    while(slow!=fast){
         prev = fast;
         slow = slow->next;
         fast = fast->next;
    }
    prev->next = NULL;
    return slow;
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
    cout<<findloop(head)<<endl;
    head = removeloop(head);
    removeloop(head);
    cout<<findloop(head)<<endl;
}