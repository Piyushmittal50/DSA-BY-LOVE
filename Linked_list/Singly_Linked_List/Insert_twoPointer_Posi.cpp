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

int findlength(node* head){
    node* temp = head;
    int len = 0;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void InsertAtMiddle(int data,node* &head,node* &tail,int k){
    // if your head and tail is null
    if(head==NULL){
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }

    // condition for only when position is 1
    if(k==1){
        node* newnode = new node(data);
        newnode->next = head;
        head = newnode;
        return;
    }
  // condition for when your position is more than the element avaliable in the LL
 // then we insert it at the last
 int len = findlength(head);
   if(k>=len){
    node* newnode = new node(data);
    tail->next = newnode;
    tail = newnode;
    return;
   }
    node* temp = head;
     for(int i=0;i<k-1;i++){
        temp = temp->next;
     }
     node* newnode = new node(data);
     newnode->next = temp->next;
     temp->next = newnode;
}
void print(node* head){
    node* temp = head;
    while(temp !=NULL){
        cout<<temp->data<<"->";
        temp= temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    
       
       node* head = new node(10);
       node* second = new node(20);
       node* third = new node(30);
       node* fourth = new node(40);
       node* fifth = new node(50);
       node* tail = new node(60);

       head->next = second;
       second->next = third;
       third->next = fourth;
       fourth->next = fifth;
       fifth->next = tail;
       tail->next = NULL;

       print(head);
       cout<<endl;
       cout<<"Head : "<<head->data<<endl;
       cout<<"Tail : "<<tail->data<<endl;
       InsertAtMiddle(35,head,tail,8);
       print(head);
       cout<<endl;
       cout<<"Head : "<<head->data<<endl;
       cout<<"Tail : "<<tail->data<<endl;
}