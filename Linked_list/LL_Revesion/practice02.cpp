// insertion in singly LL
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
void insertathead(node* &head,node* &tail,int data){
    if(head==NULL){
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
    }
    else{
        node* newnode = new node(data);
        newnode->next = head;
        head = newnode;
    }
}
void insertnode(node* &head,node* &tail,int data){  // insert at tail
    if(head==NULL){
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
    }
    else{
        node* newnode = new node(data);
        tail->next = newnode;
        tail = newnode;
    }
}
int findlength(node* &head){
    node* temp = head;
    int ans = 0;
    while(temp!=NULL){
        temp = temp->next;    // for to calculate length
        ans++;
    }
    return ans;
}
void insertatposition(node* &head,node* &tail,int data,int position){
      int length = findlength(head);
      if(head==NULL){
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
      }
    
      if(position==1){
        return insertathead(head,tail,data);
      }
      if(position>length){
          return insertnode(head,tail,data);
      }
      else{
          int i = 1;
          node* temp = head;
      while(i!=position-1){
         temp = temp->next;
         i++;
      }
      node* newnode = new node(data);
      newnode->next = temp->next;
      temp->next = newnode;
      }
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
    node* tail = NULL;
    insertnode(head,tail,10);
     insertnode(head,tail,20);
      insertnode(head,tail,30);
       insertnode(head,tail,40);
        insertnode(head,tail,50);
        insertathead(head,tail,5);
        insertatposition(head,tail,25,9);
      print(head);

}