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
node* swappingK(node* &head,int k){
    if(head==NULL || head->next ==NULL){
        return head;
    }
    node* slow = head;
    node* fast = head;
    node* n1 = head;
    
    for(int i=0;i<k-1;i++){  // n1 mil chuka hai  (n1)
      fast = fast->next;
      n1 = fast;
    }
    while(fast->next!=NULL){  // n2 bhi mil chuka hai ( slow pointer)
        fast = fast->next;
        slow = slow->next;
    }

    // now swapping
    int temp = n1->data;
    n1->data = slow->data;
    slow->data = temp;

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
    cout<<"Ans is : "<<endl;
    node* ans = swappingK(head,2);
    print(ans);
}