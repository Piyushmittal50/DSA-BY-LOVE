#include <bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertAtTail(node *&head, node *&tail, int data){
    if (head == NULL){
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
node* swapnodes(node* &head){
   if(head==NULL || head->next==NULL)
       return head;
    if(head->next->next==NULL){
        swap(head->data, head->next->data);
        return head;
    }
    node *curr = head;
    node *first = NULL;
    node *second = NULL;
    while(curr && curr->next){
        first = curr;
        second = curr->next;
        swap(first->data, second->data);
        if(curr->next->next!=NULL){
        curr = curr->next->next;
        }
        else {
            return head;
        }
    }
    return head;
}
void print(node *&head){
    node *temp = head;
    while (temp){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{
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
    node *newhead = swapnodes(head);
    print(newhead);
}