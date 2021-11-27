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

