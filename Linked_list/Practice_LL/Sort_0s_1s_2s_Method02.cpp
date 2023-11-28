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
node* sort_Elements(node* &head){
         // create dummy nodes
         node* zerohead = new node(-1);
         node* zerotail = zerohead;

         node* onehead = new node(-1);
         node* onetail = onehead;

         node* twohead = new node(-1);
         node* twotail = twohead;

      // traverse the LL
      node* curr = head;
      while(curr!=NULL){
        if(curr->data == 0){

             node* temp = curr;
             curr = curr->next;    // by appling these three lines we seprate the zero wali Node
             temp->next = NULL;
        
             // now append the zero wali node into zerohead
             zerotail->next = temp;
             zerotail = temp;
        }
        else if(curr->data ==1){
             node* temp = curr;
             curr = curr->next;    // by appling these three lines we seprate the one wali Node
             temp->next = NULL;
        
             // now append the one wali node into zerohead
             onetail->next = temp;
             onetail = temp;
        }
        else if(curr->data == 2){
             node* temp = curr;
             curr = curr->next;    // by appling these three lines we seprate the two wali Node
             temp->next = NULL;
        
             // now append the two wali node into zerohead
             twotail->next = temp;
             twotail = temp;
        }
      }
      // befor joining these nodes first we have to remove the dummy nodes 
      // modify one wali list
      node* temp = onehead;
      onehead = onehead->next;
      temp->next = NULL;
      delete temp;

      // modify 2 wali list
      temp = twohead;
      twohead = twohead->next;
      temp->next = NULL;
      delete temp;

      // join list
      if(onehead!=NULL){
        // one wali list is non-empty
        zerotail->next = onehead;
        if(twohead!=NULL){
            onetail->next = twohead;
        }
      }
      else{
        // one wali list is empty
        if(twohead!=NULL){
            zerotail->next = twohead;
        }
      }

      // remove zerohead dummy node
      temp = zerohead;
      zerohead = zerohead->next;
      temp->next = NULL;
      delete temp;
     
     // return the overall modified LL head
      return zerohead;
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
     node* head = new node(0);
    node* second = new node(1);
    node* third = new node(2);
    node* fourth = new node(0);
    node* fifth = new node(0);
    node* sixth = new node(1);
    node* seven = new node(2);
    node* eight = new node(2);
    node* nine = new node(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seven;
    seven->next = eight;
    eight->next = nine;
    nine->next = NULL;
    print(head);
    cout<<endl;
    head = sort_Elements(head);
    print(head);
    cout<<endl;


}