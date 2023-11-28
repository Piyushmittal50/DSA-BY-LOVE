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
bool isPalindrome(node* &head){
    if(head==NULL||head->next==NULL){
        return head;
    }

    // findout kara hai middle node
    node* slow = head;
    node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    // now reverse the second haif
    node* prev = NULL;
    node* curr = slow;
    while(curr){
        node* nextPointer = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextPointer;
    }

    // now compare both sides
    node* first = head;
    node* second = prev;
    while(first!=NULL && second!=NULL){
        if(first->data!=second->data) return false;
        first = first->next;
        second = second->next;
    }
    return true;
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
 node* head = new node(10);
    node* second = new node(20);
    node* third = new node(30);
    node* fourth = new node(30);
    node* fifth = new node(20);
    node* six = new node(10);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = six;
    six->next = NULL;
    print(head);
    if(isPalindrome(head)){
        cout<<"LL is palindrome"<<endl;
    }
    else cout<<"LL is not "<<endl;
}