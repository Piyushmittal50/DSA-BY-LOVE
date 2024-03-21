#include<iostream>
using namespace std;
class node{
  public :
  int data;
  node* next;
  node(int data){
  	this->data = data;
  	this->next = NULL;
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
	   node* newnode = new node(data);
       newnode->next = head;
       head = newnode;
	}
   
}
void InsertAtTail(node* &head,node* &tail,int data){
	if(tail==NULL){
		node* newnode = new node(data);
		head = newnode;
		tail = newnode;
		return;
	}
	node* newnode = new node(data);
	tail->next = newnode;
	newnode ->next = NULL;
	tail = newnode;
}

node* reverse(node* &head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	node* prev = NULL;
	node* curr = head;
	while(curr){
		node* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

node* Recursively(node* &prev,node* &curr){
   // base case
	if(curr==NULL){
		return prev;
	}
	node* next = curr->next;
	curr->next = prev;
	return Recursively(curr,next);
}
int LL_length(node* &head){
   node* temp = head;
   int i = 0;
   while(temp){
      temp = temp ->next;
      i++;
   }
   return i;
}
void insertPosition(node* head,node* &tail,int data,int position){
   if(head==NULL){
   node* newnode = new node(data);
   newnode->next = NULL;
   node* head = newnode;
   return;
   }
   int length = LL_length(head);
   if(position>=length){
      // insert At Tail
      node* newnode = new node(data);
      tail->next = newnode;
      newnode->next = NULL;
      return;
   }
    
   node* temp = head;
   for(int i=0;i<position-1;i++){
     temp = temp->next;
   }

   node* newnode = new node(data);
   node* next = temp->next->next;
   temp->next = newnode;
   newnode ->next = next;
}

void insertMiddle(node* head,int data){
   //edge case
   if(head==NULL){
      node* newnode = new node(data);
      head = newnode;
      return;
   }
   if(head->next == NULL){
      node* newnode = new node(data);
      head->next = newnode;
      newnode->next = NULL;
      return;
   }

   node* slow = head;
   node* fast = head;
   node* prev;
   while(fast->next!=NULL){
      prev  = slow;
      slow = slow->next;
      fast = fast->next;

      if(fast->next!=NULL){

         fast = fast->next;
      }
   }
   int length = LL_length(head);
   node* newnode = new node(data);
   node* next = prev->next;
   prev->next = newnode;
   newnode->next = next;
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
   insertAtHead(head,tail,10);
   insertAtHead(head,tail,20);
   insertAtHead(head,tail,30);
   insertAtHead(head,tail,40);
   insertAtHead(head,tail,50);
   insertAtHead(head,tail,60);
   print(head);
   cout<<head->data<<endl;
   cout<<tail->data<<endl;
   InsertAtTail(head,tail,0);
   InsertAtTail(head,tail,-5);
   InsertAtTail(head,tail,-10);
   InsertAtTail(head,tail,-20);
   InsertAtTail(head,tail,-30);
   InsertAtTail(head,tail,-40);
   print(head);
   cout<<head->data<<endl;
   cout<<tail->data<<endl;
   cout<<"Reversed LL : "<<endl;
   node* newHead = reverse(head);
   print(newHead);

   cout<<"Recursively Solution : "<<endl;
   node* prev = NULL;
   node* ResAns = Recursively(prev,newHead);
   print(ResAns);
   int position;
   cout<<"Enter a Position : "<<endl;
   cin>>position;
   insertPosition(head,tail,100000,position);
   print(head);
   cout<<"At Middle : "<<endl;
   insertMiddle(head,20000);
   print(head);
}