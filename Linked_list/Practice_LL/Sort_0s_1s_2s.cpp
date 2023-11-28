#include<iostream>   // method 1 
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
void sort_Elements(node* &head){
    int zeros = 0;
    int ones = 0;
    int twos = 0;
    node* temp = head;
    // step1 -> count the zeros,ones and twos
    while(temp!=NULL){
        if(temp->data==0)
            zeros++;
        else if(temp->data==1)
            ones++;
        else
            twos++;
        temp = temp->next;
    }
    // step2 -> replace the elements 
     temp = head;
     while(zeros--){
        temp->data = 0;
        temp = temp->next;
     }
     while(ones--){
        temp->data = 1;
        temp = temp->next;
     }
     while(twos--){
        temp->data = 2;
        temp = temp->next;
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
     node* head = new node(0);
    node* second = new node(1);
    node* third = new node(2);
    node* fourth = new node(0);
    node* fifth = new node(0);
    node* sixth = new node(1);
    node* seven = new node(2);
    node* eight = new node(2);
    node* nine = new node(1);

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
    sort_Elements(head);
    print(head);
    cout<<endl;
}