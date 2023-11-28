#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* prev;
    node* next;
    node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~node(){
       next = NULL;
    }
};
int getLength(node* &head){
    int len = 0;
    node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}
void insertion(node* &head,node* &tail,int data){
    if(head==NULL){
        node* newnode = new node(data);
        head = newnode;
        tail  = newnode;
        return;
    }
    node* newnode = new node(data); // new node create 
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}
void Delete(node* &head,node* &tail,int position){
    if(head==NULL){
        cout<<"LL is Empty,Cant not Delete!"<<endl;
        return;
    }
    else {
    if(head->next==NULL){  // single element
      node* temp = head;
      head = NULL;
      tail = NULL;
      delete temp;
      return;
    }
    if(position==1){
        node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }
    int length = getLength(head);
    if(position>length){
        cout<<"Please Enter a valid position!"<<endl;
        return;
    }
    if(position==length){ // delete the last node
     node* temp = tail;
     tail = tail->prev;
     temp->prev = NULL;
     tail->next =NULL;
     delete temp;
     return; 
    }
     // delete from the middle of the LL
     int i=1;
      node* left = head;
      while(i<position-1 && left!=NULL){
        left = left->next;
        i++;
      }
      node* curr = left->next;
      node* right = curr->next;
      left->next = right;
      right->prev = left;
      curr->next = NULL;
      curr->prev = NULL;
      delete curr;
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
    node* head = NULL;
    node* tail = NULL;
    insertion(head,tail,10);
    insertion(head,tail,20);
    insertion(head,tail,30);
    insertion(head,tail,40);
    insertion(head,tail,50);
    print(head);
    cout<<"Tail is : "<<tail->data<<endl;
    cout<<"After Deleting : "<<endl;
    Delete(head,tail,6);
    print(head);
}