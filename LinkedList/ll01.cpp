#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(){
        this->data = 0;
        this->next = NULL;
    }
    node(int val){
        this->data = val;
        this->next = NULL;
    }
};
void insertAtHead(node* &head,node* &tail,int data){
    // base case
    if(head==NULL) {
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
    }
    else{
    node *newnode = new node(data);
    newnode->next = head;
    head = newnode;
    }
}
void insertAtTail(node *&head, node *&tail, int data){
    if(head==NULL){
        node *newnode = new node(data);
        head = newnode;
        tail = newnode;
    }
    else{
        node *newnode = new node(data);
        tail->next = newnode;
        tail = newnode;
    }
}
int llSize(node *&head){
    node *temp = head;
    int i = 0;
    while(temp){
        i++;
        temp = temp->next;
    }
    return i;
}
void insertAtPosition(node *&head, node *&tail,int k, int data){
    int size = llSize(head);
    // base case
    if(k<=1)
        insertAtHead(head, tail, data);
    else if(k>size){
        insertAtTail(head, tail, data);
    }
    else{
    node *temp = head;
    node *prev = NULL;
    for (int i = 1; i < k ;i++){
        prev = temp;
        temp = temp->next;
    }
    node *newnode = new node(data);
    newnode->next = temp;
    prev->next = newnode;
    }
}
node* llreverse(node* &prev,node* &curr){
    // base case
    if(curr ==NULL)
        return prev;
    node *next = curr->next;
    curr->next = prev;
    return llreverse(curr, next);
}
node* findMiddle(node* &head){
    node *slow = head;
    node *fast = head;
    while(fast->next!=NULL){
        slow = slow->next;
        fast = fast->next;
        if(fast->next!=NULL){
            fast = fast->next;
        }
    }
    return slow;
}
void print(node* &head){
    node* temp = head;
    while(temp){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main(){
    node *head = NULL;
    node *tail = NULL;
    insertAtHead(head,tail, 40);
    insertAtHead(head,tail, 30);
    insertAtHead(head,tail, 20);
    insertAtHead(head,tail, 10);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, -10);
    insertAtPosition(head, tail, 2, 100);
    cout << "head is : " << head->data << endl;
    cout << "tail is : " << tail->data << endl;
    print(head);
    node *prev = NULL;
    node *newHead = llreverse(prev,head);
    cout << "Reversed ll is : " << endl;
    print(newHead);
    cout << "new head is : " << newHead->data << endl;
    node *middle = findMiddle(newHead);
    cout << "Middle of LL is : " << middle->data << endl;
}