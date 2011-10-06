#pragma once

template <typename T> 
class Stack 
{
public:

  Stack();
  ~Stack();
  Stack(const Stack &);
  Stack &operator=(const Stack &);
  
  void push(const T &)        // append an element at the end of the array
  void pop();                 // remove last element (precond: !empty)
  bool empty() const;         // true iff no element present
  int size() const;           // return current number of elements
  T &top();                   // return reference to last element (precond: !empty)
  const T &top() const;       // return const ref. ....  

private:
  T *p;                       // pointer to array of length capacity
  int capacity;               // current maximum number of elements
  int n;                      // actual number of elements (<= capacity)
};
