#include <iostream>
#include<queue>
using namespace std;
class node {
public:
  int data;
  node *left;
  node *right;
  node(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};
node *buildTree() {
  int data;
  cout << "Enter the data :" << endl;
  cin >> data;
  if (data == -1) {
    return NULL;
  }
  // step A,B and C
  // step A
  node *Root = new node(data);
  cout << "Enter the data for left part of " << data << " node " << endl;
  Root->left = buildTree();
  cout << "Enter the data for right part of " << data << " node " << endl;
  Root->right = buildTree();
  return Root;
}
void levelorder(node* &root){
  queue<node*> q;
  // initially
  q.push(root);
  q.push(NULL);
     while(!q.empty()){
      //A
      node* temp = q.front();
      //B
      q.pop();
      if(temp==NULL){
        cout<<endl;
        if(!q.empty()){
          q.push(NULL);
        }
      }
      else{
      //C
      cout<<temp->data<<" ";
      //D
      if(temp->left){
        q.push(temp->left);
      }
      if(temp->right){
         q.push(temp->right);
      }
     }
     }
}
int main() {
  node *root = NULL;
  root = buildTree();

  levelorder(root);
}