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
int getlength(node* &head){
    int len = 0;
    node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}
void insertNode(node* &head,int data){  // insert node at tail
      node* newnode = new node(data);
    if(head==NULL){
    head = newnode;
    return;
    }
   node* temp = head;
   while(temp->next!=NULL){
    temp = temp->next;
   }
    temp->next = newnode;
}
node* rotate_LL(node* &head,int k){  // k -> is the position
   if(head==NULL){
    return NULL;
   }
   int len = getlength(head);
   int rotateK = k % len;
   if(rotateK==0){
    return head;
   }
   int newlastnodepos = len - rotateK - 1;
   node* newlastnode = head;
   for(int i=0;i<newlastnodepos;i++){
    newlastnode = newlastnode->next;
   }
   node* newhead = newlastnode->next;

   newlastnode->next = NULL;

   node* it = newhead;
   while(it->next){
    it = it->next;
   }
   it->next = head;

  return newhead;
}
void print(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node* head = NULL;
    insertNode(head,10);
     insertNode(head,20);
      insertNode(head,30);
       insertNode(head,40);
        insertNode(head,50);
         insertNode(head,60);
         print(head);
         head = rotate_LL(head,2);
         print(head);
}