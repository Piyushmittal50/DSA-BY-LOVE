// findout the middle of the LL
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
node* insertnode(node* &head,node* &tail,int data){
    if(head==NULL){
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
    }
    else{
        node* newnode = new node(data);
        tail->next = newnode;
        tail = newnode;
    }
   return head;
}
node* middleelement(node* &head,node* &tail){  // using two pointer approach
    node* slow = head;
    node* fast = head ->next;
    while()
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
    insertnode(head,tail,10);
    insertnode(head,tail,20);
    insertnode(head,tail,30);
    insertnode(head,tail,40);
    insertnode(head,tail,50);
    head = insertnode(head,tail,60);
    print(head);

}