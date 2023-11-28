#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;
    node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
int getLength(node* &head){
    int len = 0;
    node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}
void insertAtHead(node* &head,node* &tail,int data){   // Time Complexity is o(1)
    if(head==NULL){  // LL s empty
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    else{  // LL is not empty
    node* newnode = new node(data);   // step1 -> node create
    newnode->next = head;  // step2 -> newnode ko head se connect karge
    head->prev = newnode;   // step3 -> ab head ko newnode se connect karge
    head = newnode;  // step4 -> head ko update kar dege

    }

}
void insertAtTail(node* &head,node* &tail,int data){
    if(head==NULL){
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    else{
        node* newnode = new node(data);  
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
}
void insertAtPosition(node* &head,node* &tail,int data,int position){  // using two pinter prev & curr
    if(head==NULL){   //LL is empty
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    else{    // LL is not empty

    if(position==1){      
        insertAtHead(head,tail,data);
        return;
    }

    int length = getLength(head);

    if(position>length){
        insertAtTail(head,tail,data);
        return;
    }
    // insertion in middle
    int i = 1;
    node* prevNode = head;
    while(i<position-1 && prevNode!=NULL){
        prevNode = prevNode->next;   // step1 -> find the prev and curr node
        i++;
    }
    node* currNode = prevNode->next;

     // step2 -> create a node
     node* newnode = new node(data);
     //step3 -> 
     newnode->prev= prevNode;
     prevNode->next = newnode;

     // step4->
       newnode->next = currNode;
       currNode->prev = newnode;
    }
}

void print(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    
    node* first = new node(10);
    node* second = new node(20);
    node* third = new node(30);
    node* fourth = new node(40);
    node* tail = fourth;

    first->prev = NULL;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = NULL;

    print(first);
    cout<<endl;
    
    insertAtHead(first,tail,5);
    print(first);
    cout<<endl;

    insertAtTail(first,tail,50);
    print(first);
    cout<<endl;

    insertAtPosition(first,tail,60,8);
    print(first);
    cout<<endl;
}