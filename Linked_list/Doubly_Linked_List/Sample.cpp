#include<iostream>
using namespace std;
class node
{
    public:
  int data;
  node *prev;
  node *next;
    node ()
  {
	this->data = 0;
	this->prev = NULL;
	this->next = NULL;
  }
  node (int data)
  {
	this->data = data;
	this->prev = NULL;
	this->next = NULL;
  }
};

void insertAtTail(node* &head,node* &tail,int data){
    if(head==NULL || tail==NULL){
        // create new node
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    // otherwise
    node* newnode = new node(data);
    newnode->prev = tail;
    tail->next = newnode->prev;
    tail->next = newnode;
    tail = newnode;
    tail->next = NULL;
}
void insertAtHead(node* &head,node* &tail,int data){
    // head==NULL
    if(head==NULL){
        node* newnode = new node(data);
        head = newnode;
        return;
    }
    // otherwise
    node* newnode = new node(data);
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}
int length(node* head){
    node* temp = head;
    int i=0;
    while(temp){
        temp = temp->next;
        i++;
    }
    return i;
}
void insertAtPosition(node* &head,node* &tail,int data,int position){
    if(head==NULL){
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    if(position==0){
        insertAtHead(head,tail,data);
        return;
    }
    int length01 = length(head);
    if( position>=length01){
        insertAtTail(head,tail,data);
        return;
    }
    // otherwise arrange
    node* temp = head;
    for(int i=0;i<position-1;i++){
        temp = temp->next;
    }
    node* store = temp->next;
    node* newnode = new node(data);
    newnode->prev = temp;
    temp->next = newnode;
    store->prev = newnode;
    newnode->next = store;
    
}
void deleteNode(node* &head,node* &tail,int pos){
    if(head==NULL){
        return;
    }
     int length01 = length(head);
    if(pos==length01){
        // Delete the last node
        tail = tail->prev;
        tail->next = NULL;
        delete head;
        head = tail; // Update head if there's only one node
        return;
        
    }
   
    node* currNode = head;
    node* prevNode = NULL;
    // delete node by pos
    int i = 0;
        while(currNode!=NULL && pos<=length01 && i<pos-1){
            prevNode = currNode;
            currNode = currNode->next;
            i++;
        }
        currNode->next->prev = prevNode;
        prevNode->next = currNode->next;
        delete currNode;
}
void print(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}
int main ()
{
  node *head = NULL;
  node *tail = NULL;
  insertAtTail (head, tail, 10);
  insertAtTail (head, tail, 20);
  insertAtTail (head, tail, 30);
  insertAtTail (head, tail, 40);
  insertAtTail (head, tail, 50);
  print(head);
  cout<<endl;
  cout<<tail->data<<"->NULL"<<endl;
  cout<<endl;
  cout<<head->data<<"->NULL"<<endl;
  insertAtHead(head,tail,0);
  insertAtHead(head,tail,-10);
  insertAtHead(head,tail,-20);
  insertAtHead(head,tail,-30);
  insertAtHead(head,tail,-40);
  insertAtHead(head,tail,-50);
  print(head);
  
  cout<<endl;
  insertAtPosition(head,tail,100,10);
  print(head);
  deleteNode(head,tail,1);
  print(head);
}
