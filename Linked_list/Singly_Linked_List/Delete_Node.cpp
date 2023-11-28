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
    // write a destructor to delete a node??
     ~node() {
        next = NULL;
     }
};
void insertnode(node* &head,node* &tail,int data){
    if(head==NULL){
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    node* newnode = new node(data);
    tail->next = newnode; // update tail node by node
    tail  = newnode;
}
 int findlength(node* head){
    node* temp = head;
    int len = 0;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}
void deletenode(node* &head,node* &tail,int k){
    if(head==NULL){
        cout<<"Can Not Delete, LL is Empty ! "<<endl;
        return;
    }
    // if you delete the first node
    if(k==1){
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    int length = findlength(head);
    // and if you want to delete last node
    if(length==k){
        node* temp = head;
       for(int i=0;i<k-2;i++){ // Move to the node before the last node
         temp = temp->next;
       }
        node* pre = temp->next;
        temp->next = NULL;
        tail = temp; // Update the tail to the new last node
      delete pre;
       return;
    }

      // If you want to delete a node in the middle of the linked list
    if (k > 1 && k < length) {
        node* temp = head;
        for (int i = 0; i < k - 2; i++) { // Move to the node before the target node
            temp = temp->next;
        }
        node* toBeDeleted = temp->next;
        temp->next = toBeDeleted->next;
        delete toBeDeleted;
        return;
    }
}
void print(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
      node* head = NULL;
      node* tail = NULL;
      insertnode(head,tail,10);
      insertnode(head,tail,20);
      insertnode(head,tail,30);
      insertnode(head,tail,40);
      insertnode(head,tail,50);
      print(head);
      cout<<endl;
      deletenode(head,tail,3);
      print(head);
}