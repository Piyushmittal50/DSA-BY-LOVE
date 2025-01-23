#include <iostream>
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
void nsert(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        node *newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    node *newnode = new node(data);
    tail->next = newnode;
    tail = newnode;
}

int findSize(node* &head){
    node *temp = head;
    int i = 0;
    while(temp){
        i++;
        temp = temp->next;
    }
    return i;
}
node* removeKth(node* &head,node* &tail,int k){
    int size = findSize(head);
 
    if (k <= 0 || k > size)
        return head;

    // If k is equal to the size, remove the head node
    if (k == size){
        node *curr = head;
        head = head->next;
        delete curr;
        if (head == nullptr) // If the list becomes empty after deletion, update the tail.
            tail = nullptr;
        return head;
    }
    if(k==1 && size>1){ // remove last node
        node *last = head;
        node *prevlast = NULL;
        while(last->next!=NULL){
            prevlast = last;
            last = last->next;
        }
        delete last;
        prevlast->next = NULL;
        tail = prevlast;
        return head;
    }

    int dis = size - k + 1;
    node *temp = head;
    node *prev = NULL;
    for (int i = 0; i < dis - 1;i++){
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    return head;
}
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    nsert(head, tail, 10);
    nsert(head, tail, 20);
    nsert(head, tail, 30);
    nsert(head, tail, 40);
    nsert(head, tail, 50);
    nsert(head, tail, 60);
    cout << "LL is : " << endl;
    print(head);

    cout << "After kth node : " << endl;
    node *ans = removeKth(head, tail, 1);
    print(ans);
}