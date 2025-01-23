#include <iostream>
#include<stack>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node()
    {
        this->data = 0;
        this->next = NULL;
    }
    node(int val)
    {
        this->data = val;
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
    }
    else
    {
        node *newnode = new node(data);
        tail->next = newnode;
        tail = newnode;
    }
}

node* sort012(node* &head){
    node *zerohead = new node(100);
    node *onehead = new node(100);
    node *twohead = new node(100);

    node *zerotail = zerohead;
    node *onetail = onehead;
    node *twotail = twohead;
    node *curr = head;

    // seperate
    while(curr){
        if(curr->data==0){
            zerotail->next = curr;
            zerotail = curr;
        } 
        else if(curr->data==1){
            onetail->next = curr;
            onetail = curr;
        }  
        else{ // 2
            twotail->next = curr;
            twotail = curr;
        }
        curr = curr->next;
    }
    zerotail->next = onehead->next;
    onetail->next = twohead->next;
    twotail->next = NULL;

    return zerohead->next;
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
    node *head = new node(0);
    node *second = new node(2);
    node *third = new node(0);
    node *fourth = new node(0);
    node *fifth = new node(2);
    node *six = new node(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = six;
    six->next = NULL;
    print(head);
    cout << "After Rearranging : " << endl;
    node *ans = sort012(head);
    print(ans);
}    