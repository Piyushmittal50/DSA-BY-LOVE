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
int main(){
	node* head = NULL;
    node* tail = NULL;
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,5);
    insertAtTail(head,tail,7);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,5);
    print(head);
}