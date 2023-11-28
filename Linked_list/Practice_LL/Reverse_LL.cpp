#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* prev;
    node* next;
    node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
int getLength(node* &head){
    int i=0;
    node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        i++;
    }
   return i;
}
void reverse_LL(node* &pre,node* &curr){
    
      while(curr!=NULL){
       node* next  = curr->next; 
       curr->next = pre;
       pre = curr;
       curr = next;
      }
    curr = pre;
}
void print(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node* head = new node(10);
     node* second = new node(20);
      node* third = new node(30);
       node* fourth = new node(40);
        node* fifth = new node(50);

        head->next = second;
        second->next = third;
        third->next = fourth;
        fourth->next = fifth;
        fifth->next = NULL;

        node* curr = head;
        node* pre = NULL;
        reverse_LL(pre,curr);
        print(head);
}