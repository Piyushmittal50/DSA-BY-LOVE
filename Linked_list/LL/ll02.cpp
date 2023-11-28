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
node* LLReverse(node* &head,node* &tail){
   if(head==NULL || head->next == NULL){
    return head;
   }

   node* prevPointer = NULL;
   node* currPointer = head;
   while(currPointer){
    node* nextPointer = currPointer->next;
    currPointer->next = prevPointer;
    prevPointer = currPointer;
    currPointer = nextPointer;
   }
   return prevPointer;
}

node* LLReverse_Recurssion(node* &prev,node* &curr){
    // base case
    if(curr==NULL){
        return prev;
    }
    node* nextNode = curr->next;
    curr->next = prev;
    return LLReverse_Recurssion(curr,nextNode);
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

//   cout<<"Reverse is : "<<endl;
//   node* newHead = LLReverse(head,tail);
//   print(newHead);
//   cout<<endl;
  node* prev = NULL;
  cout<<"Recursively : "<<endl;
  node* newhead = LLReverse_Recurssion(prev,head);
  print(newhead);
}