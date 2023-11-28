#include<iostream>
#include<unordered_set>  
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(){
        this->data = 0;
        this->next  = NULL;
    }
    node(int data){
        this->data = data;
        this->next = NULL; 
    }
};
bool check_Circular(node* &head){  // using only singal pointer
        if(head==NULL){
            return false;
        }
        node* curr = head;
        while(curr->next!=NULL && curr->next !=head){
            curr = curr->next;
        }
         if(curr->next==head){
            return true;
         }
         return false;
}
bool checkcircular(node* &head){  // using two pointer approach
node* curr = head;
if(curr==NULL){
    return false;
}
node* slow = curr;
node* fast = curr;
while(fast!=NULL && fast->next!=NULL){
    fast = fast->next->next;
    slow = slow->next;

    if(slow==fast){
        return true;
    }
}
   return false;
}
bool circularcheck(node* &head){  // using unordered_set container
       if(head==NULL){
        return false;
       }
       unordered_set<node*> visited;
       node* curr = head;
       while(curr!=NULL){
        if(visited.find(curr)!=visited.end()){
            return true;
        }
        visited.insert(curr);
        curr = curr->next;
       }
       return false;
}
void print(node* &head) {
    if (head == NULL) {
        std::cout << "Circular Linked List is empty." << std::endl;
        return;
    }

    node* current = head;

    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head);

    std::cout << std::endl;
}
int main()
{
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
    sixth->next = head;
    print(head);
    bool ans = check_Circular(head);
    if(ans == true){
        cout<<"LL is circular "<<endl;
    }
    else{
        cout<<"LL is not circular "<<endl;
    }
    
    bool result = checkcircular(head);
    if(result == true){
        cout<<"LL is circular "<<endl;
    }
    else{
        cout<<"LL is not circular "<<endl;
    }

     bool answer = circularcheck(head);
    if(answer == true){
        cout<<"LL is circular "<<endl;
    }
    else{
        cout<<"LL is not circular "<<endl;
    }
}