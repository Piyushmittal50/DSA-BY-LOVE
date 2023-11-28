// delete node in singly LL
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
void insertnode(node* &head,node* &tail,int data){
    if(head==NULL){
     node* newnode = new node(data);
     head = newnode;
     tail = newnode;
     return;
    }
    else{
        node* newnode = new node(data);
        tail->next = newnode;
        tail = newnode;
    }
}
int findlength(node* &head){
    int ans = 0;
    node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        ans++;
    }
    return ans;
}
void deletenode(node* &head,node* &tail,int position){
    int length = findlength(head);
    if(head==NULL){
        cout<<"can not delete element"<<endl;
        return;
    }
    if(head->next==NULL){
        delete head;
        return;
    }
    if(position>length){
        node* temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        temp->next = NULL;
        delete temp->next;
    }
    else{
        if(position==1){
            node* temp = head;
            head = head->next;
            delete temp;
        }
        else if(position>1 && position<=length){
        int i = 1;
        node* temp = head;
        while(i!=position-1){
          temp = temp->next;
          i++;
        }
       temp->next = temp->next->next;
        }
    }
}
void print(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node* head = NULL;
    node* tail = NULL;
    insertnode(head,tail,10);
    insertnode(head,tail,20);
    insertnode(head,tail,30);
    insertnode(head,tail,40);
    insertnode(head,tail,50);
    insertnode(head,tail,60);
    deletenode(head,tail,10);
    print(head);
}