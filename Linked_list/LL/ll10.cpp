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
node* removeDuplicate(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* curr = head;
    while(curr->next!=NULL){
        if(curr->data == curr->next->data){
            node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else{
            curr = curr->next;
        }
    }
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
 node* head = new node(10);
    node* second = new node(20);
    node* third = new node(20);
    node* fourth = new node(40);
    node* fifth = new node(40);
    node* sixth = new node(40);
   

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;
    print(head);
    cout<<"Ans is : "<<endl;
    node* ans = removeDuplicate(head);
    print(ans);
}