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
int getLength(node* &head){
    node* temp = head;
    int count = 0;
    while(temp){
    temp = temp->next;
    count++;
    }
    return count;
}
node* KnodesReverse(node* &head,int k){
    if(head==NULL || head->next==NULL){
        return head;
    }
    int length = getLength(head);
    if(k>length){
        return head;
    }
    else{
        node* prev = NULL;
        node* curr = head;
        node* forward = NULL;
        int count = 0;
        while(count<k){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }

        // now rest of will be reversed by recurssion
        if(forward!=NULL){
            head->next = KnodesReverse(forward,k);
        }
        return prev;
    }
    return NULL;
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
  node* head = new node(10);
    node* second = new node(20);
    node* third = new node(30);
    node* fourth = new node(40);
    node* fifth = new node(50);
    node* sixth = new node(60);
   

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;
    print(head);
    cout<<"After K nodes : "<<endl;
    node* ans = KnodesReverse(head,4);
    print(ans);
}