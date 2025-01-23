#include<iostream>
#include<stack>
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
// way 1
bool isPalindrome(node* &head){
    node* curr = head;
    node* temp = head;
    stack<int> s;
    while(temp!=NULL){
        s.push(temp->data);
        temp = temp->next;
    }
    // now compare 
    while(!s.empty()){
        int ele = s.top();
        if(curr->data!=ele){
            return false;
        }
        s.pop();
        curr = curr->next;
    }
    return true;
}
// way 2
bool isPalindrome01(node* &head){
    if(head==NULL||head->next==NULL){
        return true;
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

    if(isPalindrome01(head)){
        cout<<"LL is palindrome"<<endl;
    }
    else cout<<"LL is not "<<endl;
}