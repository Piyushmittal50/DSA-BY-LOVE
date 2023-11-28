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
void removeDuplicate(node* &head){
    if(head==NULL){
        cout<<"LL is empty"<<endl;
        return;
    }
    if(head->next ==NULL){
        cout<<"LL have only one element"<<endl;
        return;
    }
    node* curr = head;
    while(curr!=NULL){
        if((curr->next!=NULL) && (curr->data==curr->next->data)){
            // for equal
            node* temp = curr->next;
            curr->next = curr->next->next;
            // delete node
            temp->next = NULL;
            delete temp;
        }
        else{  
            // for not equal
            curr = curr->next;
        }
    }
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
    node* head = new node(20);
    node* second = new node(20);
    node* third = new node(20);
    node* fourth = new node(40);
    node* fifth = new node(40);
    node* sixth = new node(60);
    node* seven = new node(70);
    node* eight = new node(70);
    node* nine = new node(70);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seven;
    seven->next = eight;
    eight->next = nine;
    nine->next = NULL;
    print(head);
    cout<<endl;
    removeDuplicate(head);
    print(head);
    cout<<endl;
}