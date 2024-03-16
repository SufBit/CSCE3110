#include "splay.hpp"
using namespace std;


SplayNode* SplayTree::find(SplayNode* N, int x){
	if(N == NULL){
		return NULL;
	}
	if (x < N->element){
		return find(N->left, x);
	}
	else if(x > N->element){
		return find(N->right, x);
	}
	else{
		splay(N);
		return N;
	}
	
}


SplayNode* SplayTree::findMin(SplayNode* N){
	if(N == NULL){
		return NULL;
	}	
	if(N->left == NULL){
		splay(N);
		return N;
	}
	return findMin(N->left);
}

SplayNode* SplayTree::findMax(SplayNode* N){
	if(N == NULL){
		return NULL;
	}	
	if(N->right == NULL){
		splay(N);
		return N;
	}
	return findMax(N->right);
}

/**
 * Internal method to insert into a subtree.
 * x is the item to insert.
 * N is the node that roots the subtree.
 * Set the new root of the subtree.
 */
SplayNode* SplayTree::insert(SplayNode *& N, int x){

	if (N == NULL){

		SplayNode * newNode = new SplayNode;
		newNode -> element = x;
		newNode -> left = NULL;
		newNode -> right = NULL;
		newNode -> parent = N;
        N = newNode;
		splay(N);
		return N;
        
	}
	else if(x < N -> element){
		SplayNode * LeftChild = insert(N -> left, x);
		N -> left = LeftChild;
		LeftChild -> parent = N;
		splay(LeftChild);
		return LeftChild;
	}
	else if (x > N -> element){
		SplayNode * RightChild = insert(N -> right, x);
		N -> right = RightChild;
		RightChild -> parent = N;
		splay(RightChild);
		return RightChild;
	}
	else{
		splay(N);
		return N;
	}
}

/**
 * Internal method to remove from a subtree.
 * x is the item to remove.
 * N is the node that roots the subtree.
 * Set the new root of the subtree.
 */
SplayNode* SplayTree::remove(SplayNode *& N, int x){
	if(N == NULL){
    		return NULL;
	}
	SplayNode * tmp = find(N, x); //find node and splay
	SplayNode * left = tmp->left;
	SplayNode * right = tmp->right;
	delete tmp; //remove the node
	if (left != NULL) {
		left->parent = NULL;
		tmp = findMax(left); //find the max on the left subtree and splay
		tmp->right = right;
		if (right != NULL)
			right->parent = tmp;
	} else if (right != NULL) {
		right->parent = NULL;
		tmp = findMin(right); //find the min on the right subtree and splay
		tmp->left = NULL;
	} else {
	    return NULL;
	}

	return tmp;
}

//splay node N to root
void SplayTree::splay(SplayNode *& N){
	while(N->parent != NULL){
		if(N->parent->parent == NULL){
			if(N == N->parent->left){
				rotateWithLeftChild(N->parent);
			}
			else{
				rotateWithRightChild(N->parent);
			}
		}
		else if(N == N->parent->left && N->parent == N->parent->parent->left){
			rotateWithLeftChild(N->parent->parent);
			rotateWithLeftChild(N->parent);
		}
		else if(N == N->parent->right && N->parent == N->parent->parent->right){
			rotateWithRightChild(N->parent->parent);
			rotateWithRightChild(N->parent);	
		}
		else if(N == N->parent->right && N->parent == N->parent->parent->left){
			rotateWithRightChild(N->parent);
			rotateWithLeftChild(N->parent);
		}
		else{
			rotateWithLeftChild(N->parent);
			rotateWithRightChild(N->parent);	
		}
	}
}
//right rotation
void SplayTree::rotateWithLeftChild(SplayNode *& k2){
  SplayNode *k1 = k2->left;
  SplayNode *k2_c = k2;

  k2_c->left = k1->right;
  k1->parent = k2_c->parent;

  if(k1->parent != NULL) {
    if(k1->element < k1->parent->element)
      k1->parent->left = k1;
    else
      k1->parent->right = k1;
  }

  if(k1->right != NULL)
    k1->right->parent = k2_c;

  k1->right = k2_c;
  k2_c->parent = k1;

  //k2 = k1;
}
//left rotation
void SplayTree::rotateWithRightChild(SplayNode *& k2){
  SplayNode *k1 = k2->right;
  SplayNode *k2_c = k2;

  k2_c->right = k1->left;
  k1->parent = k2_c->parent;

  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  //if grandpa existing make sure that replace current node with the parent node as child node of grandpa
  if(k1->parent != NULL) {
    if(k1->element < k1->parent->element)
      k1->parent->left = k1;
    else
      k1->parent->right = k1;
  }
  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  if(k1->left != NULL)
    k1->left->parent = k2_c;

  k1->left = k2_c;
  k2_c->parent = k1;

  //k2 = k1;
}
//left-right rotation
void SplayTree::doubleLeftChild(SplayNode *& k3){

  rotateWithRightChild(k3->left);
  rotateWithLeftChild(k3);
}
//right-left rotation
void SplayTree::doubleRightChild(SplayNode *& k3){

  rotateWithLeftChild(k3->right);
  rotateWithRightChild(k3);
}

void SplayTree::print(SplayNode *N, int level, int type){
        //cout << "printing N: " << N << endl;
  	if (N == NULL) {
    		return;
  	}
  	if (type == IS_ROOT) {
    		std::cout << N -> element << "\n";
  	} else {
    		for (int i = 1; i < level; i++) {
      			std::cout << "| ";
    		}
    		if (type == IS_LEFT) {
      			std::cout << "|l_" << N -> element << "\n";
    		} else {
      			std::cout << "|r_" << N -> element << "\n";
    		}
  	}
  	if (N -> left != NULL) {
    		print(N -> left, level + 1, IS_LEFT);
  	}
  	if (N -> right != NULL) {
    		print(N -> right, level + 1, IS_RIGHT);
  	}
}
