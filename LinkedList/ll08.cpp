#include<bits/stdc++.h>
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
void insertAtTail(node *&head, int data){
    if (head == NULL)
    {
        node *newnode = new node(data);
        head = newnode;
        return;
    }
    else{
        // if head!=NULL
        node *newnode = new node(data);
        node *temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
    }
}
node* merge(node* &first,node* &second){
   
    if(first==NULL && second==NULL){
        return NULL;
    }
    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }
    node *dummy = new node(101);
    node *head = dummy;
    while(first!=NULL && second!=NULL){
        if(first->data <=second->data){
            dummy->next = first;
            first = first->next;
        }
        else{
            dummy->next = second;
            second = second->next;
        }
        dummy = dummy->next;
    }

    // now rest of
    if(first!=NULL)
        dummy->next = first;
    if(second!=NULL)
        dummy->next = second;

    return head->next;
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
node* multiply(node* &list1,node* &list2){
    node *first = list1;
    int x = 0;
    while(first){
        x = 10 * x + first->data;
        first = first->next;
    }
    node *second = list2;
    int y = 0;
    while(second){
        y = 10 * y + second->data;
        second = second->next;
    }
    node *head = new node(101);
    node *temp = head;
    int number = x * y;
    //cout << "number :" << number << endl;
    while(number >0){
        int data = number % 10;
        node *newnode = new node(data);
        temp->next = newnode;
        temp = newnode;
        number = number / 10;
    }

    node *newhead = reversell(head->next);
    return newhead;
}
void print(node *&head){
    node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main(){
    node *first = NULL;
    insertAtTail(first, 1);
    insertAtTail(first, 2);
    insertAtTail(first, 6);
    print(first);
    node *second = NULL;
    insertAtTail(second, 2);
    insertAtTail(second, 3);
    insertAtTail(second, 2);
    //insertAtTail(second, 18);
    //insertAtTail(second, 19);
    cout << endl;
    print(second);
    cout << "multiply of two sorted LL : " << endl;
    node *ans = multiply(first, second);
    print(ans);
}