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
        this ->next = NULL;
    }
};
void InsertAtHead(node* &head,int data){
    node* temp = new node(data);
    temp->next = head;
    head = temp;
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
    // assume the a node name as head
    node* head = NULL;
     InsertAtHead(head,20);
     InsertAtHead(head,30);
     InsertAtHead(head,40);
     InsertAtHead(head,50);
     InsertAtHead(head,60);
     InsertAtHead(head,70);

     cout<<"The LL Element Are : "<<endl;
     print(head);
}