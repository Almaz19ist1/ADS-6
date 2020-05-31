#include <iostream>



template<typename T>
class BST
{
public:
    struct Node
    {
        T value;
        int count;
        Node *left;
        Node *right;
    };
private:
    Node* root;
    Node* addNode(Node *, T);
public:
    BST();
    ~BST();
    void add(T);
};

template<typename T>
BST<T>::BST():root(nullptr) {}

template<typename T>
BST<T>::~BST() 
{
    if(root)
        delTree(root);
}


template<typename T>
typename BST<T>::Node* BST<T>::addNode(Node *root, T value) {
   if(root==nullptr) {
      root=new Node;
      root->value=value;
      root->count=1;
      root->left=root->right=nullptr;
   }
   else if(root->value>value) {
     root->left=addNode(root->left,value);
   }
   else if(root->value<value) {
     root->right=addNode(root->right,value);
   }
   else
    root->count++;
   return root;
}

template<typename T>
void BST<T>::add(T value) {
   root=addNode(root,value);
}
