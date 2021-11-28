#include <bits/stdc++.h>
using namespace std;
class AVL_T{
    public: 
        class Node{
            public:
                int data;
                Node* left;
                Node* right;
            
        Node(){
            data=0;
            left=NULL;
            right=NULL;
            }
        Node(int d){
                data=d;
                left=NULL;
                right=NULL;
            }
    };
    Node* root;

    AVL_T(){
        root=NULL;
    }

/**************************************************************************/
// -------- START Some Extra User Defined Functions -------

// START Get Balance factor of node N 
int getBalancedFac(Node* r){
    if(r==NULL)
         return -1;
    else 
        return height(r->left)-height(r->right);
}
// END Get Balance factor of node N 

// START Right Rotation
Node* rightRotate(Node* r){
    Node* newRoot=r->left; //new root
    Node* T2 = newRoot->right;

    // perform right rotation
		newRoot->right = r;
		r->left = T2;

		return newRoot;
}
// END Right Rotation

// START Left Rotation
Node* leftRotate(Node* r) {
		Node* newRoot = r->right; // new root
		Node* T2 = newRoot->left;

		// perform left rotation
		newRoot->left = r;
		r->right = T2;

		return newRoot;
	}
// END Left Rotation

// --------- END Some Extra User Defined Functions --------
/**************************************************************************/

// START 1 - Insert a Node in AVL Tree
Node* insert(Node* r,int val){
        if(r==NULL){
           return new Node(val);
        }
 		// if the value is less than the root node then recur for the left subtree
       if(val <r->data){
           r->left = insert(r->left, val );
       }
       // if the value is less than the root node then recur for the right subtree
       else if(val >r->data){
           r->right=insert(r->right,val );
       }
       // val ==root->data
       else{
           cout << "No duplicate values allowed!" << endl;
           return r;
        }
    int bf = getBalancedFac(r);
        // Left Case
        if(bf > 1 && val  < r->left->data)
              return rightRotate(r);
        // Right Case
		else if (bf < -1 && val  > r->right->data)
			return leftRotate(r);
		// Left-Right Case
		else if (bf > 1 && val  > r->left->data) {
			r->left = leftRotate(r->left);
			return rightRotate(r);
		}
		// Right-Left Case
		else if (bf < -1 && val  < r->right->data) {
			r->right = rightRotate(r->right);
			return leftRotate(r);
		}
		return r;
	}
// END 1 - Insert a Node in AVL Tree

// START 2 - Print 2D(from BinaryTree.cpp)
    void print2D(Node* root,int space){
        if(root==NULL)
             return;
        space = space+5; // Increase distance between levels   2
        print2D(root->right,space); 
        cout<<endl;
        for(int i=5;i<space;i++){
            cout<<" ";
        }
        cout<<root->data<<endl; 
        print2D(root->left,space);
    }
// END 2 - Print 2D(from BinaryTree.cpp)
 
// START 3 - Height of Tree / isBalanced?(from BinaryTree.cpp)
bool isBal = true; // only to check isBalanced?
    int height(Node* r) {
		if (r == NULL)
			return -1;

		else {
			int lheight = height(r->left);
			int rheight = height(r->right);

			// only to check isBalanced?, ignore this condition for finding the height
			if (abs(lheight - rheight) > 1) {
				isBal = false;
			}
			return max(lheight, rheight) + 1;
		}
	}
// END 3 - Height of Tree / isBalanced?(from BinaryTree.cpp)

// START 4 Delete a Node in AVL Tree
// function to find the maximum value from the left-subtree
int maxLeft(Node* node){
    if(node->right != NULL)
        return maxLeft(node->right);
    else
        return node->data;
}

Node* Delete(Node* node, int val){
    if(node == NULL)
        return NULL;
    if(val < node->data){
        node->left=Delete(node->left,val);
    }
    else if(val > node->data){
        node->right = Delete(node->right,val);
    }
    // when the node to be deleted is found
    else{
        if(node->left != NULL && node->right != NULL) 
        {
            int lmax = maxLeft(node->left);
            node->data = lmax;
            node->left = Delete(node->left,lmax);
        }
        // if the node has only a left child
        else if(node->left != NULL){
            return node->left;
        }
        // if the node has only a right child
        else if(node->right != NULL){
            return node->right;
        }
        // if the node has no child i.e., it is a leaf node
        else{
            return NULL;
        }
    }

  int bf = getBalancedFac(node);
		
		// if bf is 2, it means that the deletion will happen in the right subtree
		// this will result in L-L-Imbalance or L-R-Imbalance
		/*
		  => bf(r->left)=1 means remaining structure in this is:-
		 		30 bf=2
		 	   /
		 	  20   bf=1
		 	 /
		 	10     bf=0
		
		 => bf(r->left)=0 means remaining structure in this is:-
		 	   30 bf=2
		 	  /
		 	 20   bf=0
		 	/  \
		   10  25   bf=0 for both
	  */
		if (bf == 2 && getBalancedFac(node->left) >= 0)
			return rightRotate(node);
		else if (bf == 2 && getBalancedFac(node->left) == -1) {
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
		
		// if bf is -2, it means that the deletion will happen in the left subtree
		// this will result in R-R-Imbalance or R-L-Imbalance
		/*
		   => bf(r->right)=-1 means remaining structure in this is:-
		 		10 bf=-2
		 		  \
		 		  20 bf=-1
		 		    \
		 		    30 bf=0
		 
		
		
		  => bf(r->right)=0 means remaining structure in this is:-
		 	   10  bf=-2
		 		 \
		 		 20 bf=0
		 		/  \
		 	  15    30 bf=0 for both
	  */
		else if (bf == -2 && getBalancedFac(node->right) <= 0)
			return leftRotate(node);
		else if (bf == -2 && getBalancedFac(node->right) == 1) {
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
		return node;
  
}
// END 4 Delete a Node in AVL Tree


};

int main(){
    AVL_T avl; 
    int option,val;

    do{
        cout<<"----------------------------------------------------------------"<<endl;
        cout<<" 0 - Exit"<<endl;
        cout<<" 1 - Insert a Node in AVL Tree"<<endl;
        cout<<" 2 - Print 2D"<<endl;
        cout<<" 3 - isBalanced?"<<endl;
        cout<<" 4 - Delete a Node in AVL Tree"<<endl;
        cout<<"----------------------------------------------------------------"<<endl;

    cin>>option;
    AVL_T* n = new AVL_T();

    switch(option){

        case 0:
            break;
        
        case 1:
            cout<<"Enter value to Insert: ";
            cin>>val;
            avl.root=avl.insert(avl.root,val);
            break;

        case 2:
            avl.print2D(avl.root,5);
            break;
        
        case 3:
            avl.height(avl.root);
            cout<<avl.isBal<<endl;
            break;
        
        case 4:
            cout<<"Enter the value to delete : ";
            cin>>val;
            avl.root=avl.Delete(avl.root,val);
            break;

        default:
        cout<<"INVALID CHOICE";
    }
    }while(option!=0);
    return 0;
}