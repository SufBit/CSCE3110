#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>

#define IS_ROOT 0
#define IS_LEFT 1
#define IS_RIGHT 2

struct SplayNode {
    int element;
    SplayNode *left;
    SplayNode *right;
    SplayNode *parent;

};


using namespace std;
class SplayTree{
private:
//public:
  SplayNode * r; // the actual SplayTree
public:
  SplayNode * root() { return r; }
  SplayTree(){
    r = NULL; // constructor
  };
  ~SplayTree(){};      // destructor
  SplayNode * findMin(SplayNode * N);
  SplayNode * findMax(SplayNode * N);
  SplayNode* find(SplayNode* N, int x);

  SplayNode * findMin() { return findMin(r); }
  SplayNode * findMax(){ return findMax(r); }
  SplayNode* find(int x){ return find(r, x);}

  SplayNode* insert(SplayNode *& N, int x);
  SplayNode* remove(SplayNode *& N, int x);
  void splay(SplayNode *& N); 

  void insert(int x) { r = insert(r, x); }
  void remove(int x) { SplayNode* tmp = remove(r, x);
		       r = (tmp == NULL)? r : tmp;}
  
  void rotateWithLeftChild(SplayNode *& k2);
  void rotateWithRightChild(SplayNode *& k2);

  void doubleLeftChild(SplayNode *& k3);
  void doubleRightChild(SplayNode *& k3);
  
  void print() {
  	print(r, 0, IS_ROOT);
  }
  void print(SplayNode *N, int level, int type);
};

