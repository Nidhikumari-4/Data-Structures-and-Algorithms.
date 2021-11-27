# **What is Balanced BT ?**

### Binary tree where the difference between the height of left subtree and right subtree **for every node** is not more than k(usually k=1). This difference is called balanced factor. **bf=|height of LST - height of RST|**.

### So for every node **height of LST - height of RST** should be {-1,0,1}.

# **AVL TREE**
### **[Video Reference](https://youtu.be/u3OVSkuOdqI)**


### AVL Tree is a self-balancing BST (i.e., basically a BST which remains balanced even though you insert or delete nodes).

## <u> **Ways of Balancing AVL Tree** </u>

### To maintain the balance in AVL Tree(i.e to be AVL tree always) while inserting and deleting, we perform Rotations. Depending on different imbalance cases, we have 4 basic types of rotations –

- **LEFT LEFT Imbalance/case - RIGHT Rotation**
- **RIGHT RIGHT Imbalance/case - LEFT Rotation**
- **LEFT RIGHT Imbalance/case - LEFT RIGHT Rotation**
- **RIGHT LEFT Imbalance/case - RIGHT LEFT Rotation**

### **[Video Reference](https://youtu.be/_nyt5QYel3Q)**

![AVL Tree Rotation](https://user-images.githubusercontent.com/64855541/122770456-1522f400-d2c3-11eb-9d95-7bba74a9afc8.jpg)

<hr>

##  **INSERTION IN AVL TREE** 

### **Step 1 (Optional) : [Theoretical Insertion in AVL Tree](https://youtu.be/f0BplF93TIA)**

### **Step 2 : [Practical Insertion in AVL Tree dry run + code](https://youtu.be/otiDcwZbCo4)**

```cpp
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
```

## **DELETION IN AVL TREE**

<img width="960" alt="AVL Tree Deletion" src="https://user-images.githubusercontent.com/64855541/122783991-b021cb00-d2cf-11eb-8af2-00c64f83af94.png">

### **Step 1: [Practical Implementation of Deletion in AVL Tree](https://youtu.be/3UivJWAFaI4)**

```cpp
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
```
