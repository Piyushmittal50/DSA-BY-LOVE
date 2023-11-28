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
void insertAtHead(node* &head,int data){
         node* newnode = new node(data);
         if(!head){
            head = newnode;
            newnode->next = head;
            return;
         }
         else{
            
            node* temp = head;
            
            while(temp->next!=head){
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
            head = newnode;
         }

}
void print(node* head) {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }

    node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "..." << endl;
}
int main(){
    node* head  = NULL;
    int data = 0;
    for (int i=1 ;i<=5;++i) {
        data = data +10;
        insertAtHead(head,data);
    }
   print(head);
}