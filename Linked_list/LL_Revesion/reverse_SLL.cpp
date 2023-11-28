#include<iostream>   // for SLL
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
void insertnode(node* &head,node* &tail,int data){
    node* newnode = new node(data);
    if(head==NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    else{
        tail->next = newnode;
        tail = newnode;
        return;
    }
}
node* reversenode_basic(node* &head,node* &tail){
    node* prev = NULL;
    node* curr = head;
    node* next = curr->next;
    while(curr!=NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    
    }
    return prev;
}
node* reversenode_recursive(node* &curr,node* prev = NULL){ 
    if(curr==NULL){
        return prev;
    }
    node* next = curr->next;
    curr->next = prev;
    return reversenode_recursive(next,curr);
}
void print(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node* head = NULL;
    node* tail = NULL;
    insertnode(head,tail,10);
    insertnode(head,tail,20);
    insertnode(head,tail,30);
    insertnode(head,tail,40);
    insertnode(head,tail,50);
    insertnode(head,tail,60);
    insertnode(head,tail,70);
     print(head);
    head =  reversenode_basic(head,tail);
    print(head);
    head = reversenode_recursive(head);
     print(head);
}