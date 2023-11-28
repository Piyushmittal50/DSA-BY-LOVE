// delete element from the doubly LL
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
        newnode->prev = tail;
        tail = newnode;
        tail->next = NULL;
    }
}
int findlength(node* &head){
    int i = 0;
    node* temp = head;
    while(temp!=NULL){
        temp = temp ->next;
        i++;
    }
    return i;
}
void deletenode(node* &head,node* &tail,int position){
    int length = findlength(head);
    if(head==NULL){
        cout<<"can not delete element"<<endl;
        return;
    }
    if(position<=0){   
        cout<<"invalid posotion"<<endl;
        return;
    }
    if(position>length){
      node* temp = head;
      while(temp->next->next!=NULL){   // when the position > length
        temp  = temp->next;
      }
      node* del = temp->next;
      temp->next = NULL;
      delete del;
    }
    if(position==1){
            node* first = head;
            head = head->next;
            head->prev = NULL;
            delete first;
    }
    else if(position==length){
        node* last = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete last;
    }
    else if(position>1 && position<length){  // delete element by position
          int i = 1;
            node* curr = head;
            while(i!=position && position!=1){
                curr = curr->next;
                i++;
            }
            node* nextnode = curr->next;
            node* dele = curr;
            node* prevnode  = curr->prev;
            prevnode->next  = nextnode;
            delete dele;
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
    deletenode(head,tail,0);
    print(head);
}