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
int findLength(node* &head){
    int len= 0 ;
    node* temp = head;
    while(temp!=NULL){
       temp = temp->next;
       len++;
    }
    return len;
}
int findMiddle(node* &head){
        node* temp = head;
        int length = findLength(head);
        if(length%2==0){  // even length
          int middle = length/2;
          int i= 1;
          while(i<middle){
              head = head->next;
              i++;
          }
          int val = head->data;
          return val;
        }
        else{ // odd length
            int middle = length/2 +1;
             int i= 1;
          while(i<middle){
              temp = temp->next;
              i++;
          }
          int val = temp->data;
          return val;
        }

        return -1;
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

    node* head = new node(10);
    node* second = new node(20);
    node* third = new node(30);
    node* fourth = new node(40);
    node* fifth = new node(50);
    node* sixth = new node(60);
    node* seventh = new node(70);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = NULL;
    print(head);
    cout<<"Middle element is -> "<< findMiddle(head);

}