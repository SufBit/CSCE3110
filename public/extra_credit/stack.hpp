//#include <bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>

// Ideally this would not be a huge number, you could also use a vector
//#define MAXSIZE 100000

template<typename T>
struct Node{
	T item;
	Node* next;
};

using namespace std;
template<class T>
class Stack{
private:
  Node<T> *top; // the actual stack
  int list_size;
  //Node top;   // index of the top element
public:
  Stack(){
    top = NULL; // constructor
    list_size = 0;
  };
  ~Stack(){};      // destructor
  void push(T c);  // push c to the list
  T pop();         // return and remove the top element in the stack
  bool isEmpty();
  T peek();      // return the top element in the stack
  int size();      // returns the size of the stack
  void display();  // display the stack in stdout
};
