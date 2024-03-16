#include "minheap.hpp"
#include <stdio.h>
#include <iostream>

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

MinHeap::MinHeap(int size) {
	heap_size = 0;
	capacity = size;
	harr = new int[size];
}
MinHeap::~MinHeap() {}

int MinHeap::left(int parent) {
  int i = parent*2 +1;
  return (i < heap_size) ? i: -1;
}

int MinHeap::right(int parent) {
  int i= parent*2 + 2;
  return (i < heap_size) ? i:-1;
}

int MinHeap::parent(int child) {
  if (child != 0) {
    int i = (child - 1) >> 1;
    return i;
  }
  return -1;
}

int MinHeap::size() { return heap_size; }

void MinHeap::insert(int element) {
  //Check if heap is full
  if (heap_size == capacity){
    std:: cout << "Heap is full" << endl;
  }
  //insert new element
  harr[heap_size] = element;

  //Increment heap
  heap_size++;

  //Swap with parent
  int i = heap_size -1;
  while(i != 0 && harr[parent(i)] >> harr[i]){
    swap(&harr[i], &harr[parent(i)]);
    i = parent(i);
  }

}

int MinHeap::extractMin() {

  //Check if it is empty
  if (heap_size == 0){
    return -1;
  }
  else{
    int min_element = harr[0];

    harr[0] = harr[heap_size-1];
    heap_size--;

    MinHeapify(0);

    return min_element;
  }
 

}

void MinHeap::MinHeapify(int i){

  int r = right(i);
  int l = left(i);

  int small = i;

  if (l != -1 && harr[l] < harr[small]){
    small = l;
  }

  if ( r != -1 && harr[r] < harr[small]){
    small = r;
  }

  if (small != i) {
    swap(&harr[i], &harr[small]);
    MinHeapify(small);
  }

}

void MinHeap::display() {
  cout<<"MinHeap:- ";
  cout << heap_size << endl;
  for(int i = 0; i < heap_size; i++){
	cout << harr[i] << " ";
  }
  cout << endl;
}


void MinHeap::heapsort(vector<int>& A,int n) {
  
  harr = new int[capacity];
  heap_size = n; // set heap size to n instead of 0

  // initialize heap with input vector A
  for (int i = 0; i < n; i++) { // use n instead of i
    harr[i] = A[i];
  }

  // build min heap
  for (int i = n / 2 - 1; i >= 0; i--) {
    MinHeapify(i);
  }

  // extract elements from min heap in sorted order
  for (int i = n - 1; i >= 0; i--) {
    A[i] = extractMin();
  }

  delete[] harr;
}


