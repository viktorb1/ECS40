#include <stdexcept>
#include <iostream>
#include <cassert>

template <typename T>
BSTNode<T>::BSTNode(const T &valu, BSTNode<T>* lef, BSTNode<T> *righ) : 
value(valu), left(lef), right(righ)
{
} // BSTNode() constructor


template <typename T>
BST<T>::BST() : root(NULL)
{
} // BST() constructor


template <typename T>
void BST<T>::push(const T &value)
{
  push(value, root);
} // push()


template <typename T>
void BST<T>::push(const T &value, BSTNode<T>* &node)
{
  if (node == NULL)
    node = new BSTNode<T>(value, NULL, NULL);
  else // node is != NULL (not at the end of the tree)
  {
    if (value < node->value)
      push(value, node->left);
    else // go right if the value is larger
      push(value, node->right);
  } // if the node is still not NULL, continue down the tree
} // push() recursive


template <typename T>
void BST<T>::pop(T &value)
{
  assert(root != NULL);
  pop(value, root);
} // pop() 


template <typename T>
void BST<T>::pop(T &value, BSTNode<T>* &node)
{
  if(root == NULL)
    throw out_of_range("BST underflow error.");

  if (node->left)
    pop(value, node->left);
  else // the tree is at the final left node
  {
    value = node->value;
    BSTNode<T>* temp = node;

    if(node->right)
    {
      node = new BSTNode<T>(node->right->value, NULL, NULL);
      delete node->right;
    } // if a right node exists in the last left node of the tree
    else // a right node did not exist
      node = NULL;

    delete temp;
  } // the node is pointing to the smallest value
} // pop() recursive

