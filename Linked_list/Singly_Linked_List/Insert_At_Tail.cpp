#include<iostream>
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
void InsertAtHead(node* &head,node* &tail,int data){
    // used to create new node
     node* newnode = new node(data);
     // if head is NULL then make new node as head
     if(head==NULL){
        head = newnode;
        tail = newnode;
     }
     else{
        newnode->next = head;
     }
     head = newnode;

}
void InsertAtTail(node* &head,node* &tail,int data){
      // create a new node
      node* newnode  = new node(data);
      // if head is null then make a new node as head
      if(head==NULL){
        head = newnode;
        tail = newnode;
      }
      else{
        tail->next = newnode;
      }
      tail =newnode;
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

     node* head = NULL;
     node* tail = NULL;
     
     InsertAtHead(head,tail,10);
     InsertAtHead(head,tail,20);
     InsertAtHead(head,tail,30);

     InsertAtTail(head,tail,5);
     InsertAtTail(head,tail,1);
     print(head);
     return 0;
}