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
node* reversenode(node* &head){
    node* prev = NULL;
    node* curr = head;
    node* next = curr->next;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;  
    }
    return prev;
}
bool check_Palimdrome(node* &head){
    if(head==NULL){
        return false;
    }
    if(head->next == NULL){
        return true;
    }
    // step1 -> find the middle node
    node* slow = head;
    node* fast = head->next;
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }

    } // after completing loop now the slow pointer pointing to middle node
      // slow -> middle

    // step2 -> reverse LL after the middle node
    node* reversekahead = reversenode(slow->next);
    // now link the middle -> to new head
    slow->next = reversekahead;

    // step3 -> now comparing the both side  before middle or after middle
     node* temp1 = head;
     node* temp2 = reversekahead;
     while(temp2!=NULL){
        if(temp1->data != temp2->data){
            return false;
        }
        else{
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
     }
    return true;
}
void print(node* head){
    node* temp = head;
    while(temp !=NULL){
        cout<<temp->data<<"->";
        temp= temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
       node* head = new node(10);
       node* second = new node(20);
       node* third = new node(30);
       node* fourth = new node(20);
       node* fifth = new node(20);
       
       
       head->next = second;
       second->next = third;
       third->next = fourth;
       fourth->next = fifth;
       fifth->next = NULL;
      
       print(head);
       cout<<endl;
       bool palindrome = check_Palimdrome(head);
       if(palindrome){
        cout<<"LL is palindrome"<<endl;
       }
       else{
        cout<<"LL is not palindrome"<<endl;
       }
      
}