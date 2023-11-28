// sort LL
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
node* merge(node* &list1,node* &list2){
    node* dummy = new node(0);
    node* curr = dummy;
    while(list1 && list2){
        if(list1->data <= list2->data){
           curr->next = list1;
           list1 = list1->next;
        }
        else{
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }
    if(list1) curr->next = list1;
    if(list2) curr->next = list2;
    return dummy->next;
}
node* sortList(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* slow = head;
    node* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    // dividing the list into two parts
    fast = slow->next;
    slow->next = NULL;

    // sort and merge
    head = sortList(head);
    fast = sortList(fast);

    return merge(head,fast);
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
 node* head = new node(6);
    node* second = new node(5);
    node* third = new node(3);
    node* fourth = new node(4);
    node* fifth = new node(7);
    node* six = new node(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = six;
    six->next = NULL;
    print(head);

    node* ans = sortList(head);
    print(ans);
}
