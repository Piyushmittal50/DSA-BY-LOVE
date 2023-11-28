// swap nodes in pair
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
node* swapnode(node* &head){
 if(head==NULL || head->next==NULL){
    return head;
   }
   node* first = head;
   node* second = head->next;

   node* temp = swapnode(second->next);
   first->next = temp;
   second->next = first;
   return second;
}
void print(node* &head){
    node* temp = head;
    while(temp){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
 node* head = new node(6);
    node* second = new node(5);
    node* third = new node(3);
    node* fourth = new node(4);
    node* fifth = new node(7);
    node* six = new node(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = six;
    six->next = NULL;
    print(head);
    cout<<"Swap pair : "<<endl;
    node* ans = swapnode(head);
    print(ans);
}    