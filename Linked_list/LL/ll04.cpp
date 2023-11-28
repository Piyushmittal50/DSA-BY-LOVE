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
node* MergeTwoSortedLL(node* &first,node* &second){
   if(first==NULL){
    return second;
   }
   if(second==NULL){
    return first;
   }

   // Dummy node
   node* dummy = new node(101);
   node* head = dummy;
   while(first!=NULL && second!=NULL){
    if(first->data <= second->data){
        dummy->next = first;
        first = first->next;
    }
    else{
        dummy->next = second;
        second = second->next;
    }
    dummy = dummy->next;
   }

   // rest Ele
   if(first!=NULL) dummy->next = first;
   if(second!=NULL) dummy->next = second;
   return head->next;
}