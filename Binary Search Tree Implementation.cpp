#include<bits/stdc++.h>
using namespace std;

struct Node{
  int value;
  Node *left;
  Node *right;
};
class BinaryTree{
  public:
    BinaryTree();
    ~BinaryTree();

    void insert(int key);
    Node *search(int key);
    void destroy_tree();
    void inorder_print();
    void postorder_print();
    void preorder_print();

  private:
    void insert(int key, Node *leaf);
    Node* search(int key, Node *leaf);
    void destroy_tree(Node *leaf);
    void inorder_print(Node *leaf);
    void postorder_print(Node *leaf);
    void preorder_print(Node *leaf);

    Node* head;
};

BinaryTree::BinaryTree(){
  head = NULL;
}

BinaryTree::~BinaryTree(){
  destroy_tree();
}

void BinaryTree::insert(int key){
  if(head != NULL){
    insert(key, head);
  }else{
    head = new Node;
    head->value = key;
    head->left = NULL;
    head->right = NULL;
  }
}

void BinaryTree::insert(int key, Node *leaf){
  if(key < leaf->value){
    if(leaf->left !=NULL)
    {
      insert(key, leaf->left);
    }else{
      leaf->left = new Node;
      leaf->left->value = key;
      leaf->left->left = NULL;
      leaf->left->right = NULL;
    }
  }else{
    if(leaf->right !=NULL)
    {
      insert(key, leaf->right);
    }else{
      leaf->right = new Node;
      leaf->right->value = key;
      leaf->right->left = NULL;
      leaf->right->right = NULL;
    }
  }
}

Node* BinaryTree::search(int key){
  return search(key, head);
}

Node* BinaryTree::search(int key, Node* leaf){
  if(leaf != NULL){
    if(leaf->value == key)
    {
      return leaf;
    }else if(key < leaf->value)
    {
      return search(key, leaf->left);
    }else{
      return search(key, leaf->right);
    }
  }else{
    return NULL;
  }
}

void BinaryTree::destroy_tree(){
  destroy_tree(head);
}

void BinaryTree::destroy_tree(Node* leaf){
  if(leaf != NULL){
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

void BinaryTree::postorder_print(){
  postorder_print(head);
  cout<<endl;
}

void BinaryTree::preorder_print(){
  preorder_print(head);
  cout<<endl;
}

void BinaryTree::inorder_print(){
  inorder_print(head);
  cout<<endl;
}

void BinaryTree::postorder_print(Node *leaf){
  if(leaf != NULL){
    postorder_print(leaf->left);
    postorder_print(leaf->right);
    cout<<leaf->value<<", ";
  }
}

void BinaryTree::preorder_print(Node *leaf){
  if(leaf != NULL){
    cout<<leaf->value<<", ";
    preorder_print(leaf->left);
    preorder_print(leaf->right);
  }
}

void BinaryTree::inorder_print(Node *leaf){
  if(leaf != NULL){
    inorder_print(leaf->left);
    cout<<leaf->value<<", ";
    inorder_print(leaf->right);
  }
}

int main()
{
  BinaryTree* head = new BinaryTree();

  head->insert(5);
  head->insert(6);
  head->insert(4);
  head->insert(3);
  head->insert(2);
  head->insert(7);
  head->insert(8);
  head->insert(9);

  head->inorder_print();
  head->preorder_print();
  head->postorder_print();

  delete head;
	return 0;
}

