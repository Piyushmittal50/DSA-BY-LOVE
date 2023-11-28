#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(){ // constructor
    this->data = 0;
    this->next = NULL;
    }
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(node* &head,int data){
    node* newnode = new node(data);
    node* temp = head;
    if(head==NULL){  // LL is empty
     node* temp = newnode;
     temp->next = NULL;
    }

    temp->next = newnode;
    newnode->next = NULL;
}

void print(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
   cout<<"NULL"<<endl;
}

int main(){
    node* head = NULL;
    insertAtHead(head,10);
    insertAtHead(head,20);
    insertAtHead(head,30);
    insertAtHead(head,40);
    insertAtHead(head,50);

    print(head);
}