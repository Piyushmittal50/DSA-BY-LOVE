// reverse k nodes
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertAtTail(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        node *newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    else
    {
        // if head!=NULL
        node *newnode = new node(data);
        tail->next = newnode;
        tail = newnode;
    }
}
int findSize(node *&head)
{
    node *temp = head;
    int i = 0;
    while (temp)
    {
        i++;
        temp = temp->next;
    }
    return i;
}
node *reversell(node *&head)
{
    node *prev = NULL;
    node *curr = head;
    while (curr)
    {
        node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
node* kreverse(node* &head,int k){
    int size = findSize(head);
    if(k>size ||k<=0|| k==1 || head==NULL || head->next==NULL){
        return head;
    }
    if(k==size){
        node *newhead = reversell(head);
        return newhead;
    }
    
        node *curr = head;
        node *prev = NULL;
        node *next = NULL;
        int count = 0;
        while(count<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(next!=NULL){
            head->next = kreverse(next, k);
        }
    return prev;
}
void print(node *&head)
{
    node *temp = head;
    while (temp)
    {
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
    node *newhead = kreverse(head,6);
    print(newhead);
}