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
int findMiddle(node* &head){
    node* temp = head;
    node* slow = head;
    node* fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
                                    //while(slow!=null &&fast!=null){
        fast = fast->next->next;    // fast = fast->next;
        slow = slow->next;          // if(fast!=null){   
                                    // fast = fast->next                                     
    }                               // slow = slow->next }  
    int val = slow->data;
    return val;
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

    node* head = new node(10);
    node* second = new node(20);
    node* third = new node(30);
    node* fourth = new node(40);
    node* fifth = new node(50);
    node* sixth = new node(60);
   

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;
    print(head);
    cout<<"Middle element is -> "<< findMiddle(head);

}