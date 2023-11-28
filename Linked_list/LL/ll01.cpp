#include<iostream>
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
void insertAtHead(node* &head,node* &tail,int data){
    if(head==NULL){
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    else{
        tail = head;
        node* newnode = new node(data);
        newnode->next = head;
        head = newnode;
    }
}
void insertAtTail(node* &head,node* &tail,int data){
   if(head==NULL){
    return insertAtHead(head,tail,data);
   }
   else{
    while(tail->next!=NULL){
        tail = tail->next;
    }
    node* newnode = new node(data);
    tail->next = newnode;
    tail = newnode;
   }
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
  insertAtHead(head,tail,0);
  insertAtHead(head,tail,-10);
  insertAtHead(head,tail,-20);
  insertAtHead(head,tail,-30);
  insertAtHead(head,tail,-40);
  insertAtTail(head,tail,10);
  insertAtTail(head,tail,20);
  insertAtTail(head,tail,30);
  insertAtTail(head,tail,40);
  print(head);
}