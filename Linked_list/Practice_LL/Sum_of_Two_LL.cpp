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
node* reverse(node* &head){
    node* prev = NULL;
    node* curr = head;
    node* forward = curr->next;

    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
node* merge_of_two_LL(node* &head1,node* &head2){
       if(head1==NULL){
        return head2;
       }
      if(head2==NULL){
        return head1;
      }

    // step1 -> reverse the both LL
     head1 = reverse(head1);
     head2 = reverse(head2);

     // step2 -> add both LL
     node* anshead = NULL;
     node* anstail = NULL;
     int carry = 0;
     while(head1 !=NULL && head2 !=NULL){
        // calculate sum
        int sum = carry + head1->data + head2->data;
        // find digit for create node
        int digit = sum % 10;
        // calculate carry
         carry = sum / 10;


        // now create a new node for that digit
        node* newnode = new node(digit);
        // attach the new node into ans wali LL
        if(anshead==NULL){
            // it means first node insert karo
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

     // jab head1 list ki length haed2 list se jada hogi
     while(head1!=NULL){
        int sum = carry + head1->data;
        int digit = sum % 10;
         carry = sum /10;
        node* newnode = new node(digit);
        anstail->next = newnode;
        anstail = newnode;
        head1 = head1->next;
     }

     // jab head2 list ki length head1 list sai jada ho
     while(head2!=NULL){
     int sum = carry + head2->data;
     int digit = sum % 10;
      carry = sum / 10;
     node* newnode = new node(digit);
     anstail ->next = newnode;
     anstail = newnode;
     head2 = head2->next;
     }
     // handle karo carry ko alag se
     while(carry!=0){
        int sum = carry;
        int digit = sum % 10;
         carry = sum / 10;
        node* newnode = new node(digit);
        anstail->next = newnode;
        anstail = newnode;
     }

     // step3 -> now reverse the ans LL
     anshead = reverse(anshead); 
     return anshead;
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
    node* head1 = new node(2);
    node* second1 = new node(4);

    node* head2 = new node(2);
    node* second2 = new node(4);
    node* third2 = new node(6);

    head1->next = second1;
    second1->next = NULL;

    head2->next = second2;
    second2->next = third2;
    third2->next = NULL;

    node* ans = merge_of_two_LL(head1,head2);
    print(ans);
    cout<<endl;
}