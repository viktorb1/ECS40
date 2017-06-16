#include <iostream>
#include <fstream>
#include "stack.h"
#include "queue.h"
#include "BST.h"

using namespace std;


int main(int argc, char **argv)
{
  ifstream inf(argv[1]);
  int size, value = -1, i = 1;
  char container, operation;
  
  inf >> size;
  cout << i++ << " Queue size ";

  Stack<int> myStack;
  Queue<int> myQueue(size);
  BST<int> myBST;

  cout << size << endl;

  while(inf >> container && inf >> operation)
  {
    cout << i++ << " " << container << operation << " ";

    switch (container)
    {
      case 'S' :
        switch (operation)
        {
          case 'P' :
            try
            {
              myStack.pop(value);
            } // check if stackList is empty
            catch(const out_of_range &oor)
            {
              cout << oor.what();
            } // print out message if exception is thrown

            break;

          case 'U' :
            inf >> value;
            myStack.push(value);
            break;
        } // operation being performed on stack

        break;
      case 'Q' :
        switch (operation)
        {
          case 'P' :
            try
            {
              myQueue.pop(value);
            } // check if queueVector is empty
            catch(const out_of_range &underflow)
            {
              cout << underflow.what();
            } // print out message if exception is thrown

            break;
          case 'U' :
            try
            {
              inf >> value;
              myQueue.push(value);
            } // check if count is smaller than size
            catch(const Whoops &overflow)
            {
              cout << overflow.what();
            } // prints message if too many elements in queue

            break;
        } // operation being performed on queue

        break;
      case 'B' :
        switch (operation)
        {
          case 'P' :
            try
            {
              myBST.pop(value);
            } // check if the tree is empty
            catch(const out_of_range &oor)
            {
              cout << oor.what();
            } // print out message if tree is empty (exception is thrown)
            
            break;

          case 'U' :
            inf >> value;
            myBST.push(value);
            break;
        } // operation being performed on binary search tree

        break;  
    } // type of container

    cout << " " << value << endl;
    value = -1;
  } // while commands in the file still exist

  return 0;
} // main()