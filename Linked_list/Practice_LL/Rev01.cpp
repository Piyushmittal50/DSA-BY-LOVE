// craete a LL and implement the basic operation

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

void insertAtHead(node* &head,node* &tail,int data){
    // base case for if there is zero node
    if(head==NULL){
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    else{
        node* newnode = new node(data);
        newnode->next = head;
        head = newnode;
    }
}
void insertAtTail(node* &head,node* &tail,int data){  // with tail node
    // if there is zero element present in the LL
    if(head==NULL){
        return  insertAtHead(head,tail,data);
    }
    else{
        node* newnode = new node(data);
        tail->next = newnode;
        tail = newnode;
    }
}
void insertatTail(node* &head,int data){
    node* temp = head;
    node* tail = head;
    if(head == NULL){
        return insertAtHead(head,tail,data);
    }
   
    while(temp!=NULL){
        temp = temp->next;
    }
    node* newnode = new node(data);
    temp->next = newnode;
    tail = newnode;
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
    // create a new node 

    node* head = new node(10);
    node* second = new node(20);
    node* third = new node(30);
    node* fourth = new node(40);
    node* fifth = new node(50);

    // link these nodes 

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;
    node* tail = fifth;

    print(head);
    cout<<endl;
    insertAtHead(head,tail,5);
    print(head);
    cout<<endl;
    insertAtTail(head,tail,60);
    print(head);
    cout<<endl;
    insertatTail(head,70);
    print(head);
    cout<<endl;
}