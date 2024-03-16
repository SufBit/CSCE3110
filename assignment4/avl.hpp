#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>

#define IS_ROOT 0
#define IS_LEFT 1
#define IS_RIGHT 2

struct AvlNode {
    int element;
    AvlNode *left;
    AvlNode *right;
    int height;

};


using namespace std;
class AvlTree{
//private:
public:
  AvlNode * r; // the actual AvlTree
public:
  AvlNode * root() { return r; }
  AvlTree(){
    r = NULL; // constructor
  };
  ~AvlTree(){};      // destructor
  bool contains(AvlNode * N, int x);
  AvlNode * findMin(AvlNode * N);
  AvlNode * findMax(AvlNode * N);

  bool contains(int x) { return contains(r, x); }
  AvlNode * findMin() { return findMin(r); }
  AvlNode * findMax(){ return findMax(r); }

  void insert(AvlNode *& N, int x);
  bool remove(AvlNode *& N, int x);
  int height(AvlNode * N);
  void balance(AvlNode *& N);
  
  void insert(int x) { insert(r, x); }
  bool remove(int x) { return remove(r, x); }
  int height() {return height(r); }
  void balance() { balance(r); }
  
  void rotateWithLeftChild(AvlNode *& k2);
  void rotateWithRightChild(AvlNode *& k2);

  void doubleLeftChild(AvlNode *& k3);
  void doubleRightChild(AvlNode *& k3);
  
  void print() {
  	print(r, 0, IS_ROOT);
  }
  void print(AvlNode *N, int level, int type);
};

