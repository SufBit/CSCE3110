#include "stack.hpp"

using namespace std;

template<class T>
void Stack<T>::push(T c){
  //always push the node on the top of the stack/linked-list
    //Create a new node pointer
    Node<T> *head = new Node<T>;
    //assign C to the item in the node
    head -> item = c;
    //Make the next point to the previous top, so if stack was A, B, C, then C would ppint to B
    head -> next = top;
    //Make new node the head
    top = head;
    //Increment size of list
    list_size++;
}

template<class T>
T Stack<T>::pop(){

  //Check if stack is empty or not
  if (isEmpty()){
    cout << "Can not pop, stack is empty" << endl;
    return T();
  }

  //Create a temporary node, which is the top of stack
  Node <T> * temp = top;

  //Read in current item in the top node, to use it to return. 
  T item = top -> item;
  //Changing the top node
  top = top ->next;
  //Remove the node
  delete temp;
  list_size--;
  return item; 
}

template<class T>
bool Stack<T>::isEmpty(){

  //Just check is stack is empty
  if (top == NULL){
    return true;
  }
  else{
    return false;
  }

}

template<class T>
T Stack<T>::peek(){
  if(isEmpty()){
    cout<<"Cannot peek. Stack empty."<<endl;
  }
  
  return top->item;
}

template<class T>
int Stack<T>::size(){
  return list_size;
}

template<class T>
void Stack<T>::display(){
  Node<T> *head = top;
  while(head != NULL){
    head = head->next;
    cout << head->item << ", ";
  }
  cout<<endl;
}

template class Stack<char>;
template class Stack<int>;
