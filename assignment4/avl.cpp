#include "avl.hpp"
using namespace std;
/*Expected output 
30
|l 20
|r 100
| |l 50

50
|l 20
|r 100

50
|l 20
|r 900
| |l 100
| |r 990
*/
static const int BALANCE = 1;

bool AvlTree::contains(AvlNode * N, int x){
	if(N == NULL){
		return false;
	}
	else if(x < N->element){
		return contains(N->left, x);
	}
	else if(x > N->element){
		return contains(N->right, x);
	}
	else{
		return true;
	}
}

AvlNode* AvlTree::findMin(AvlNode* N){
	if(N == NULL){
		return NULL;
	}	
	if(N->left == NULL){
		return N;
	}
	return findMin(N->left);
}

AvlNode* AvlTree::findMax(AvlNode* N){
	if(N == NULL){
		return NULL;
	}	
	if(N->right == NULL){
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
void AvlTree::insert(AvlNode *& N, int x){
	if (N == NULL){
		AvlNode * newNode = new AvlNode;
		newNode ->element = x;
		newNode -> left = NULL;
		newNode -> right = NULL;
		newNode -> height = 1;
        N = newNode;
        
	}
	else if (x < N ->element){
		insert(N ->left, x);
	}
	else if (x > N -> element){
		insert(N -> right, x);
	}
	//Update height
	N -> height = 1 + max(height(N->left), height(N ->right));
	balance(N);
}

/**
 * Internal method to remove from a subtree.
 * x is the item to remove.
 * N is the node that roots the subtree.
 * Set the new root of the subtree.
 */
bool AvlTree::remove(AvlNode *& N, int x){
    //If no child nodes
	if (N == NULL){
        return false;
    }
    //If element is found
    else if (N ->element == x){
        if (N -> left == NULL && N->right == NULL){
            delete N;
            N = NULL;
        }
        //If node has left child node
        else if (N ->left != NULL && N->right == NULL){
            AvlNode *temp = N;
            N = N -> left;
            delete temp;
        }
        //if node has right child node
        else if (N ->right != NULL && N->left == NULL){
            AvlNode *temp = N;
            N = N -> right;
            delete temp;
        }
        //If node has two child nodes
        else {
            AvlNode *temp = findMax(N -> left);
            N -> element = temp -> element;
            remove(N -> left, temp -> element);
            N->height = 1 + max(height(N->left), height(N ->right));
            balance(N);
        }
        return true;
    }

    else if (x < N -> element){
        bool removed = remove(N -> left, x);
        if (removed){
            //N -> height--;
            N->height = 1 + max(height(N->left), height(N ->right));
            //balance(N);
        }
        return removed;
    }
    else {
        bool removed = remove(N -> right, x);
        if(removed){
            //N -> height--;
            N->height = 1 + max(height(N->left), height(N ->right));
            //balance(N);
        }
        return removed;
    }
    
    
}

/**
 * Returns the height of the node root or -1 if nullptr 
 */
int AvlTree::height(AvlNode * N){
	return N == NULL ? -1 : N->height;
}
//rebalancing the tree by performing appropriate 
//rotation on the subtree rooted with N
void AvlTree::balance(AvlNode *& N){
    //Check if left subtree is taller
    int bFactorL = height(N -> left) - height(N -> right);
    //check if right subtree is taller
    //int bFactorR = height(N -> right) - height ( N -> left);
    if (N == NULL){
        return;
    }
    if (bFactorL > 1){
        if (height(N->left->right) <= height(N->left->left)) {
            //Left-right rotation 
            rotateWithLeftChild(N);
        }
        else {
            //LeftLeft rotation
            doubleLeftChild(N);
        }

    }
    if (bFactorL < -1){
        if (height(N -> right -> left) <= height (N -> right -> right)){
            rotateWithRightChild(N);
            
        }
        else{
           doubleRightChild(N);
        }
    }
    N->height = max(height(N->left), height(N->right)) + 1;


}
//right rotation
void AvlTree::rotateWithLeftChild(AvlNode *& k2){

  AvlNode *k1 = k2->left;
  k2->left = k1->right;
  k1->right = k2;
  k2->height = max(height(k2->left), height(k2->right) ) + 1;
  k1->height = max(height(k1->left), k2->height ) + 1;
  k2 = k1;
}
//left rotation
void AvlTree::rotateWithRightChild(AvlNode *& k2){

  AvlNode *k1 = k2->right;
  k2->right = k1->left;
  k1->left = k2;
  k2->height = max(height(k2->right), height(k2->left) ) + 1;
  k1->height = max(height(k1->right), k2->height ) + 1;
  k2 = k1;
}
//left-right rotation
void AvlTree::doubleLeftChild(AvlNode *& k3){

  rotateWithRightChild(k3->left);
  rotateWithLeftChild(k3);
}
//right-left rotation
void AvlTree::doubleRightChild(AvlNode *& k3){

  rotateWithLeftChild(k3->right);
  rotateWithRightChild(k3);
}

void AvlTree::print(AvlNode *N, int level, int type){
        //cout << "printing N: " << N << endl;
  	if (N == NULL) {
                cout << "test!" << endl;
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
