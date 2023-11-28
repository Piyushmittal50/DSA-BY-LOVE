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
        node* curr = head;
        node* prev = NULL;
        node* nextPointer = NULL;
        while(curr){
        nextPointer = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextPointer;
    }
    return prev;        
}
void nsert(node* &head,node* &tail,int data){
    if(head==NULL){
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    node* newnode = new node(data);
    tail->next = newnode;
    tail = newnode;
}
node* removeKth(node* &head,node* &tail,int k){
    // Reverse LL
    node* newhead = reverseLL(head);
    node* prev = NULL;
    node* curr = newhead;
    for(int i=0 ;i<k-1;i++){
        if(curr!=NULL){
            prev = curr;
            curr = curr->next;
        }
    }
    prev->next = curr->next;
    node* newHead = reverseLL(newhead);
    return newHead;
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
   nsert(head,tail,10);
   nsert(head,tail,20);
   nsert(head,tail,30);
   nsert(head,tail,40);
   nsert(head,tail,50);
   nsert(head,tail,60);
   cout<<"LL is : "<<endl;
   print(head);

   cout<<"After kth node : "<<endl;
   node* ans = removeKth(head,tail,2);
   print(ans);
}