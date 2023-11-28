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
    ~node(){
        next = NULL;
    }
};
void insertAtHead(node* &head,node* &tail,int data){
   if(head==NULL){
    node* newnode = new node(data);
    head = newnode;
    tail = newnode;
    return;
   }
   else{
    tail = head;
    node* newnode = new node(data);
    newnode->next = head;
    head  = newnode;
   }
}

void insertAtTail(node* &head,node* &tail,int data){
    if(head==NULL){
       return insertAtHead(head,tail,data);
    }
    else{
        while(tail->next!=NULL){
            tail = tail->next;
        }
        node* newnode = new node(data);
        tail->next = newnode;
        tail = newnode;
    }
}
int getPosition(node* &head){
    node* temp = head;
    int len = 0;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}
void insertAtPosition(node* &head,node* &tail,int data,int position){
    int len = getPosition(head);
        if(position==0){
            return insertAtHead(head,tail,data);
        }
        else{
            if(position>=len){
              return insertAtTail(head,tail,data);
            }
            if(position<len){
                  node* pre = head;
                  int count = 1;
                  while(count!=position){
                       pre = pre->next;
                       count++;
                  }
                  node* newnode = new node(data);
                  newnode->next = pre->next;
                  pre->next = newnode;
            }
        }
}
void deletenode(node* &head,node* &tail,int position){
    if(head==NULL){
        return;
    }

    else{ 

       if(position==0){

    if(head->next==NULL){ 
        delete head;
        head = NULL;
        tail = NULL;
     }
     else {
     node* temp = head;
     head = head->next;
     delete temp;
       }
    }
    int len = getPosition(head);
    if(position>=len-1){
        node* temp = head;
    while(temp->next!=tail){
        temp = temp->next;
    }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }
     else if(position>=1 && position<len-1){
        node* pre = head;
        for(int i=0;i<position-1;i++){
            pre = pre->next;
        }
        node* del = pre->next;
        pre->next = del->next;
        delete del;
    }

    }
    
}
void print(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp ->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node* head = NULL;
    node* tail = NULL;
    int data = 0;
    for( int i= 0;i<5;i++){
       data = data + 10;
       insertAtHead(head,tail,data);
    }
    print(head);
    insertAtTail(head,tail,60);
    print(head);

    insertAtPosition(head,tail,35,5);
    print(head);
    deletenode(head,tail,7);
    print(head);
}