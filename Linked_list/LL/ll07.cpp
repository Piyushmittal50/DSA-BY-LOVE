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
node* findLOOP(node* &head){
  if(head==NULL || head->next==NULL){
    return NULL;
  }

  // two pointer
  node* slow = head;
  node* fast = head;
  while(fast!=NULL){
    fast = fast->next;
    if(fast!=NULL){
        fast = fast->next;
        slow = slow->next;
    }

    if(fast==slow){
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
  }
  return NULL;
}

int main(){
    node* head = new node(10);
    node* second = new node(20);
    node* third = new node(30);
    node* fourth = new node(40);
    node* fifth = new node(50);
    node* sixth = new node(60);
    node* seven = new node(70);
    node* eight = new node(80);
    node* nine = new node(90);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seven;
    seven->next = eight;
    eight->next = nine;
    nine->next = fifth;

    node* ans = findLOOP(head);
    cout<<"Starting node is : "<<ans->data<<endl;
}
