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
void insertAtTail(node* &head,node* &tail,int data){
   if(head==NULL){
     node* newnode = new node(data);
     head = newnode;
     tail = newnode;
     return;
   }
   else{
    node* newnode = new node(data);
    tail->next = newnode;
    tail = newnode;
   }
}
// Approach 1
// int Middle(node* &head,node* &tail){
//     int count = 0;
//     node* temp = head;
//     while(temp!=NULL){
//         temp = temp->next;
//         count++;
//     }
//     int mid = (count+1)/2;
//     node* prev = NULL;
//     for(int i=0;i<mid;i++){
//         prev = head;
//         head = head->next; 
//     }
//    return prev->data;
// }
// Approach 2
node* FindMiddle(node* &head,node* &tail){
    if(head==NULL){
        return head;
    }
    node* slow = head;  // move by 1
    node* fast = head;  // move by 2
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
void print(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}
int main(){
   node* head = NULL;
  node* tail = NULL;

  insertAtTail(head,tail,10);
  insertAtTail(head,tail,20);
  insertAtTail(head,tail,30);
  insertAtTail(head,tail,40);
  insertAtTail(head,tail,50);
  print(head);
 //cout<<"Middle Ele is : "<<Middle(head,tail)<<endl;

 node* ans = FindMiddle(head,tail);
 cout<<"Middle Ele is : "<<ans->data<<endl;
}