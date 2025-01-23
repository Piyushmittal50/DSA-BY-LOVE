#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node *next;
        node(int data){
            this->data = data;
            this->next = NULL;
        }
};
void insertAtTail(node* &head,node* &tail,int data){
   if(head==NULL) {
       node *newnode = new node(data);
       head = newnode;
       tail = newnode;
       return;
   }
   else{
    // if head!=NULL
    node *newnode = new node(data);
    tail->next = newnode;
    tail = newnode;
   }
}
node* evenodd(node* &head){
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;
    node *oddhead = new node(0);
    node *oddtail = oddhead;
    node *evenhead = new node(0);
    node *eventail = evenhead;
    node *curr = head;
    while(curr){

        oddtail->next = curr;
        oddtail = curr;
        
        curr = curr->next;
        if(curr!=NULL){
        eventail->next = curr;
        eventail = curr;
        curr = curr->next;
        }
       
    }
    oddtail->next = evenhead->next;
    eventail->next = NULL;
    return oddhead->next;
}
node *evenodd(node *&head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;

    // Initialize pointers for odd and even lists
    node *oddHead = new node(-1);  // Dummy node for odd list
    node *evenHead = new node(-1); // Dummy node for even list
    node *oddTail = oddHead;
    node *evenTail = evenHead;

    // Traverse the original list and split into odd and even lists
    node *curr = head;
    bool isOdd = true; // Flag to keep track of odd and even nodes

    while (curr != NULL)
    {
        if (isOdd)
        {
            oddTail->next = curr;
            oddTail = curr;
        }
        else
        {
            evenTail->next = curr;
            evenTail = curr;
        }
        curr = curr->next;
        isOdd = !isOdd; // Toggle the flag for next iteration
    }
    
    oddTail->next = evenHead->next;
    evenTail->next = NULL; 


    node *result = oddHead->next;

    // Delete the dummy nodes
    delete oddHead;
    delete evenHead;

    return result;
}

void print(node* &head){
    node *temp = head;
    while(temp){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main(){
    node *head = NULL;
    node *tail = NULL;
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);
    insertAtTail(head, tail, 70);
    print(head);
    node *newhead = evenodd(head);
    print(newhead);
}