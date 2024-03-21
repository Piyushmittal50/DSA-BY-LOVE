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
node* merge(node* &first,node* &second){
   if(first==NULL) return second;
   if(second==NULL) return first;
   node* dummy  = new node(1000);
   node* head = dummy;
   while(first!=NULL && second!=NULL){

   	if(first->data>=second->data){
      dummy->next = second;
      second = second->next;
   	}
   	else{
   		dummy->next = first;
   		first = first->next;
   	}
   	dummy = dummy->next;
   }

   if(first!=NULL) dummy->next = first;
   if(second!=NULL) dummy->next = second;
   return head->next;
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
    node* first = new node(10);
    node* second = new node(19);
    node* third = new node(30);
    node* fourth = new node(47);
    node* fifth = new node(90);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    node* first01 = new node(5);
    node* second01 = new node(25);
    node* third01 = new node(39);
    node* fourth01 = new node(50);
    node* fifth01 = new node(67);

    first01->next = second01;
    second01->next = third01;
    third01->next = fourth01;
    fourth01->next = fifth01;
    fifth01->next = NULL;

    cout<<"printing the LL"<<endl;
    print(first);
    print(first01);
    node* newHead = merge(first,first01);
    cout<<"merged LL is : "<<endl;
    print(newHead);
}