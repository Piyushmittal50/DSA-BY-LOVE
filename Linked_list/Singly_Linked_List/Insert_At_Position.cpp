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
void insertAtPosition(node* &head,node* &tail,int data,int k){
    if(head==NULL){
        head = new node(data);
        tail = head;
        return;
    }
    node* temp = head;
    for(int i=0;i<k-1;i++){
        temp = temp->next;
    }
    node* newnode = new node(data);
    newnode->next = temp->next;
    temp->next = newnode;
    if(temp == tail){
        tail = newnode;
    }
}
void print(node* &head){
    node* temp = head;
    while(temp !=NULL){
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
    node* tail = new node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = tail;
    tail->next = NULL;
    insertAtPosition(head,tail,60,3);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    print(head);
}