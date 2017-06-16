#ifndef _BST_
#define _BST_

template <typename T>
class BST;

template <typename T>
class BSTNode
{
  const T value;
  BSTNode<T> *left, *right;
  BSTNode(const T &valu, BSTNode<T>* lef, BSTNode<T> *righ);
  friend class BST<T>;
}; // BSTNode class


template <typename T>
class BST
{
  BSTNode<T> *root;
  void push(const T &value, BSTNode<T>* &node);
  void pop(T &value, BSTNode<T>* &node);
public:
  BST();
  void push(const T &value);
  void pop(T &value);
}; // BST class


#include "BST.cpp"

#endif