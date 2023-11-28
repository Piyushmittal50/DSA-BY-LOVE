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
node* evenodd(node* &head){
    if(head==NULL || head->next ==NULL){
        return head;
    }
    node* evenhead = new node(0);
    node* oddhead = new node(0);

    node* curr = head;
    node* eventail = evenhead;
    node* oddtail = oddhead;
    while(curr){
        if(curr->data%2==0){ // even 
          eventail->next = curr;
          eventail = curr;
        }
        else{
             oddtail->next = curr;
             oddtail = curr;
        }
        curr = curr->next;
    }

    // now merge even and odd
    eventail->next = oddhead->next;
    oddtail->next = NULL;

    head = evenhead->next;

    delete evenhead;
    delete oddhead;

    return head;
}
void print(node* &head){
    node* temp = head;
    while(temp){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
 node* head = new node(6);
    node* second = new node(5);
    node* third = new node(3);
    node* fourth = new node(4);
    node* fifth = new node(7);
    node* six = new node(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = six;
    six->next = NULL;
    print(head);
    cout<<"after even and odd : "<<endl;
    node* ans = evenodd(head);
    print(head);
}    