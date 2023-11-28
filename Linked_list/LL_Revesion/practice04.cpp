// doubly LL insertion 
#include<iostream>
using namespace std;
class node{
  public:
  int data;
  node* prev;
  node* next;
  node(int data){
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
  }
};
node* insertnode(node* &head,node* &tail,int data){  // at tail
     node* newnode = new node(data);
     tail->next = newnode;
     newnode->prev = tail;
     newnode->next = NULL;
     tail = newnode;
     return tail;
}
node* inserthead(node* &head,node* &tail,int data){
    node* newnode = new node(data);
    newnode->next = head;
    head->prev = newnode;
    newnode->prev = NULL;
    head = newnode;
    return head;
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
node* insertposition(node* &head,node* &tail,int data,int position){
    int length = findlength(head);
    if(position==1){
        return inserthead(head,tail,data);
    }
    else{
        if(position>1 && position<=length){
            int i = 1;
            node* temp = head;
            while(i!=position-1){
                temp = temp->next;
                i++;
            }
            node* newnode = new node(data);
            newnode->next = temp->next;
            temp->next->prev = newnode;
            temp->next = newnode;
            newnode->prev = temp;
        }
        else if(position>length){
            node* temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            node* newnode = new node(data);
            temp->next = newnode;
            newnode->prev = temp;
            newnode->next = NULL;
            tail = newnode;
        }
    }
    return head;
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
    node* head = new node(10);
    node* second = new node(20);
    node* third = new node(30);
    node* fourth = new node(40);
    node* fifth = new node(50);
    node* sixth = new node(60);

    head->prev = NULL;
    head->next = second;

    second->prev = head;
    second->next = third;

    third->prev = second;
    third->next = fourth;

    fourth->prev = third;
    fourth->next = fifth;

    fifth->prev = fourth;
    fifth->next = sixth;

    sixth->prev = fifth;
    sixth->next = NULL;
    node* tail = sixth;
    tail = insertnode(head,tail,70);
    cout<<"tail is "<<tail->data<<endl;
    head = inserthead(head,tail,5);
    cout<<"head is "<<head->data<<endl;

    head = insertposition(head,tail,15,2);
    print(head);
}   