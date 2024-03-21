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
node* reverseLL(node* &head){
   if(head==NULL || head->next == NULL){
    return head;
   }
    node* curr = head;
    node* prev = NULL;
    while(curr){
        node* nextPointer = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextPointer;
    }
    return prev;
}
node* mergeTwo(node* &head1,node* &head2){
	if(head1==NULL) return head2;
	if(head2==NULL) return head1;
   
    head1 = reverseLL(head1);
    head2 = reverseLL(head2);

    node* anshead = NULL;
    node* anstail = NULL;
    int carry = 0;
	while(head1!=NULL && head2!=NULL){
     int sum = head1->data + head2->data + carry;
     int num = sum%10;
     carry = sum/10;

     node* newnode = new node(num);
     if(anshead==NULL){
     	anshead = newnode;
     	anstail = newnode;
     }
     else{
     	anstail->next = newnode;
     	anstail = newnode;
     }
     head1 = head1->next;
     head2 = head2->next;
 }

       while(head1 !=NULL){
        int sum = head1->data + carry;
        int num = sum%10;
        carry = sum/10;
        node* newnode = new node(num);
        anstail->next = newnode;
        anstail = newnode;
        head1 = head1->next;
     }
     while(head2 !=NULL){
        int sum = head2->data+carry;
        int num = sum%10;
        carry = sum/10;
        node* newnode = new node(num);
        anstail->next = newnode;
        anstail = newnode;
        head2 = head2->next;
     }
      while(carry!=0){
        int sum = carry;
        int num = sum%10;
        carry = sum/10;
        node* newnode = new node(num);
        anstail->next = newnode;
        anstail = newnode;
     }
     anshead = reverseLL(anshead);
     return anshead;
}
void insertAtTail(node* &head,node* &tail,int data){
   if(head==NULL){
     node* newnode = new node(data);
     head = newnode;
     tail = newnode;
     return;
   }

   node* newnode = new node(data);
   tail->next = newnode;
   newnode->next = NULL;
   tail = newnode;
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
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,5);
    insertAtTail(head,tail,7);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,5);
    print(head);

    
    node* head1 = NULL;
    node* tail1 = NULL;
    insertAtTail(head1,tail1,2);
    insertAtTail(head1,tail1,2);
    insertAtTail(head1,tail1,4);
    insertAtTail(head1,tail1,7);
    print(head1);
    cout<<"Sum of Two LL : "<<endl;
    node* ans = mergeTwo(head,head1);
    print(ans);
}