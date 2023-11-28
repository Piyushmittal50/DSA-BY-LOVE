#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(){
        this->data = 0;
        this->next = NULL;
    }
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};
int getLength(node* head){
    int len = 0;
    node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}
node* K_Nodes_Reverse(node* &head,int k){
    int length = getLength(head);
    if(head==NULL){
        cout<<"Can't not reverse "<<endl;
        return head;
    }
    if(k>length){
      return head;
    }
    else{
        // step1 -> reverse first k elements using loop
        node* pre = NULL; 
        node* curr = head;
        node* forward = curr->next;

        int count = 0;
        while(count<k){
          forward = curr->next;
          curr->next = pre;
          pre = curr;
          curr = forward;
          count++;
        }
        // step2 -> rest of the elemnts should be reversed using recursion 
        // and also here we also connect the LL 
        if(forward!=NULL){  // it means there is still elements in LL which also be reversed
              head->next = K_Nodes_Reverse(forward,k);
        }

        // step2-> return the head of modified LL
        return pre;
    }
    return NULL;
}
void print(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp ->next;
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
    head =  K_Nodes_Reverse(head,3);
    print(head);
}