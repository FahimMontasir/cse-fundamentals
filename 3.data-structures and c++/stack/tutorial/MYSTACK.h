#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int value;
  Node *next;
  Node *prev;
  Node(int val)
  {
    value = val;
    next = NULL;
    prev = NULL;
  }
};

class Stack
{
  Node *head;
  Node *top;
  int count = 0;

public:
  Stack()
  {
    head = NULL;
    top = NULL;
  }
  // PUSH
  void push(int val)
  {
    Node *newNode = new Node(val);

    if (head == NULL)
    {
      head = top = newNode;
      count++;
      return;
    }
    top->next = newNode;
    newNode->prev = top;
    top = newNode;
    count++;
  }
  // POP
  int pop()
  {
    Node *delNode;
    delNode = top;
    int chk = -1;
    if (head == NULL)
    {
      cout << "Stack underflow";
      return chk;
    }
    if (top == head)
    {
      head = top = NULL;
    }
    else
    {
      top = delNode->prev;
      top->next = NULL;
    }

    chk = delNode->value;
    delete delNode;
    count--;
    return chk;
  }
  // EMPTY
  bool empty()
  {
    if (head == NULL)
      return true;
    else
      return false;
  }
  // SIZE
  int size()
  {
    return count;
  }
  // TOP
  int topV()
  {
    if (top == NULL)
    {
      cout << "Stack underflow. There is no top" << endl;
      return -1;
    }
    else
      return top->value;
  }
};
