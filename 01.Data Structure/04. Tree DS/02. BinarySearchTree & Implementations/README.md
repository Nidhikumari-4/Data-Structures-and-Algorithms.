<h1 align="center"><b>BINARY SEARCH TREE & IMPLEMENTATIONS</b></h1>

# **Binary Search Tree**

## Binary search tree (BST) is a binary tree data structure, in which **the values in the left sub-trees of every node are smaller and the values in the right sub-trees of every node are larger.**

![](https://cdn.shortpixel.ai/client/to_avif,q_glossy,ret_img,w_1880/https://simplesnippets.tech/wp-content/uploads/2020/10/binary-tree-vs-binary-search-tree-diagram.png)

<hr>

# Prerequisites:

- ## **[Recursion by Apna College](https://www.youtube.com/playlist?list=PLy-G6jmofTJVCsc-tDDn8URgxHj9I4D9f)**


# **Implementations:**

1. ### Insert a Node(Iterative Approach)
2. ### Insert a Node(Recursive Approach)
3. ### Insert a Node(Level Order Insertion)
4. ### Print 2D
5. ### Height of tree
6. ### Sum of all Nodes in the Tree
7. ### Total Number of Nodes in the Tree
8. ### Maximum Value in the Binary Tree
9. ### Print Level Order/Breadth First Search (using queue)
10. ### Print Level Order/Breadth First Search (using Recursion)
11. ### Print Given Level of the Tree
12. ### Sum of values at level K
13. ### Print Pre-Order Traversal (NODE, LEFT, RIGHT)
14. ### Print In-Order Traversal (LEFT, NODE, RIGHT)
15. ### Print Post-Order Traversal (LEFT, RIGHT, NODE)
16. ### Print all Paths from Root to Leaf Nodes
17. ### Search in Binary Search Tree (Iterative Approach)
18. ### Search in Binary Search Tree (Recursive Approach)
19. ### Diameter of Binary Tree (O(n^2) Approach)
20. ### Diameter of Binary Tree (O(n) Approach)
21. ### Delete a Node
22. ### Construct BT from Pre-Order and In-Order
23. ### Construct BT from Post-Order and In-Order
24. ### Construct BST from In-Order
25. ### Construct BST from Pre-Order
26. ### Construct BST from Post-Order
27. ### Check if the Binary Tree is Balanced

<hr>

## **0 - Class Definition containing all above Functions**
```cpp
class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(){
            data=0;
            left=NULL;
            right=NULL;
        }

        Node(int val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
    };
    class BST{
    public:
    Node *root;

    BST(){
        root = NULL;
    }
    bool isTreeEmpty(){
         if (root == NULL) {
      return true;
    } else 
      return false;
    }

    // all above functions like insertion, deletion, printing, traversing will be here
};

```
## **1 - Insert a Node (Iterative Approach)**

## **[Video Reference](https://youtu.be/6U4K-7fu_4A)**
<br>

![](https://i.ibb.co/Z8j9KS4/Insertion-Pseudocode.png)

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions

        case 1:
            cout<<"Enter value : ";
            cin>>val;
            bt.insertNodeITTE(val);
            break;

// START	 1  - Insert a Node(Iterative Approach)
    void insertNodeITTE(int data){
        Node* n=new Node(data);
        if(isTreeEmpty()){
            root=n;
            cout<<"Value Inserted as root Node";
        }
        else{
            Node* temp=root;
            while(temp!=NULL){
                // check if the value already exists at the current node
                if(n->data==temp->data){
                    cout<<"Value already exists";
                    return;
                }
                // to insert in the left position
                else if(n->data<temp->data&&temp->left==NULL){
                    temp->left=n;
                    cout<<"Value inserted to left";
                    break;
                }
                // to traverse to the left node
                else if(n->data<temp->data){
                    temp=temp->left;
                }
    			// to insert in the right position            
                else if(n->data>temp->data&&temp->right==NULL){
                    temp->right=n;
                    cout<<"Value inserted to right";
                    break;
                }
                // to traverse to the right node
                else{
                    temp=temp->right;
                }
            }
        }
    }
    //END 1 - Insert a Node(Iterative Approach)
```
<hr>

## **2 - Insert a Node(Recursive Approach)**

## **[Video Reference](https://youtu.be/x6t1lKzjGhY)**

![](https://i.ibb.co/vcbxQjB/bst-insert-recursive.png)

```cpp
    // main fun calling
    BST bt; // BST is a class that contains all functions
    case 2:
            cout<<"Enter Value : ";
            cin>>val;
            n->data=val;
            bt.insertRecursive(bt.root,val);
            break;

   // START	2  - Insert a Node(Recursive Approach)
    Node* insertRecursive(Node* root, int val){
        //Node* n=new Node(val);
        // if the root is null, create a new node and return it
        if(root==NULL){
           return new Node(val);
        }
 	// if the value is less than the root node then recur for the left subtree
       if(val<root->data){
           root->left = insertRecursive(root->left, val);
       }
       // if the value is less than the root node then recur for the right subtree
       else if(val>root->data){
           root->right=insertRecursive(root->right,val);
       }
       else{ 
           cout << "No duplicate values allowed!" << endl;
       }
       return root;
    }
    // END 2 - Insert a Node(Recursive Approach)
```

<hr>

## **3 - Insert a Node(Level Order Insertion)**

## **[Video Reference](https://www.youtube.com/watch?v=86g8jAQug04&ab_channel=mycodeschool)**

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
        case 3:
            cout<<"Enter Value : ";
            cin>>val;
            bt.insertLevelOrder(bt.root,val);
            break;

//START 3 - Insert a Node(Level Order Insertion)
    void insertLevelOrder(Node* rt, int val){
        Node* nn=new Node(val);
        if(rt==NULL){
            rt=nn;
            cout<<"Value Inserted as root Node"<<endl;;
            root=rt;
            return ;   
        }
        queue<Node*> Q;
        Q.push(rt);

        while(!Q.empty()){
            Node* n=Q.front();
            Q.pop();

            if(n->left==NULL){
                n->left=nn;
                cout<<"Value inserted at the left."<<endl;
                root=rt;
                return;
            } else if(n->right==NULL){
                n->right=nn;
                cout<<"Value inserted at the right."<<endl;
                root=rt;
                return;
            } else {
                Q.push(n->left);
                Q.push(n->right);
            }
        }
    }
    // END 3 - Insert a Node(Level Order Insertion)
```

<hr>

## **4 - Print 2D**

## **[Video Reference](https://youtu.be/xhkSiIeTKQo)**

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
        case 4:
            bt.print2D(bt.root,5);
            break;

// START 4 - Print 2D
    void print2D(Node* root,int space){
        if(root==NULL)
             return;
        space = space+5; // Increase distance between levels   2
        print2D(root->right,space); 
        cout<<endl;
        for(int i=5;i<space;i++){
            cout<<" ";
        }
        cout<<root->data<<endl;;
        print2D(root->left,space);
    }
// END 4 - Print 2D

```
<hr>

## **5 - Height of Tree**

## **[Video Reference](https://www.youtube.com/watch?v=M-ovXwd6_0I)**

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
        case 5:
           cout<<"Height of Tree is : "<< bt.Height(bt.root)<<endl;   
           break;

// START 5 - Height of Tree
   int Height(Node* r){
       if(r==NULL){
           return -1;
       }
       else{
           int lheight=Height(r->left);
           int rheight=Height(r->right);

           if(lheight>rheight)
               return (lheight+1);
           else
              return (rheight+1); 
       }
   }
// END 5 - Height of Tree
```

<hr>

## **6 - Sum of all Nodes in the Tree**

## **[Video Reference](https://www.youtube.com/watch?v=Uze4GgUj3Fs)**

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
       case 6:
           cout<<"Sum of Tree is : "<< bt.sumOfNodes(bt.root)<<endl;   
           break; 
           
// START 6 - Sum of all Nodes in the Tree
   int sumOfNodes(Node* r){
       if(r==NULL)
           return 0;

      else{
          int lsum=sumOfNodes(r->left);
          int rsum=sumOfNodes(r->right);
          return lsum + rsum + r->data;
      }
   }
// END 6 - Sum of all Nodes in the Tree
```

<hr>

## **7 - Total Number of Nodes in the Tree**

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
       case 7:
           cout<<"Total no. Of Nodes are : "<< bt.countNodes(bt.root)<<endl;   
           break;    

// START 7 - Total Number of Nodes in the Tree
    int countNodes(Node* r){
       if(r==NULL)
           return 0;

      else{
          int lcount=countNodes(r->left);// count the total nodes in left subtree
          int rcount=countNodes(r->right);// count the total nodes in right subtree
          return lcount +rcount +1;//+1 for root 
      }
   }
// END 7 - Total Number of Nodes in the Tree
```

<hr>

## **8 - Maximum Value in the Binary Tree**

## **[Video Reference](https://www.youtube.com/watch?v=SImAcxdgorU)**

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
        case 8:
           cout<<"Maximum Value in the Binary Tree is : "<<bt.maxValue(bt.root)<<endl;
           break;  

// START 8 - Maximum Value in the Binary Tree
int maxValue(Node* r) {
		if (r == NULL)
			return 0;
		int lmax = maxValue(r->left); // find the Maximum Value in the left subtree
		int rmax = maxValue(r->right); // find the Maximum Value in the right subtree
		return max(r->data, max(lmax, rmax));
	}
// END 8 - Maximum Value in the Binary Tree

```

<hr>

## **9 - Print Level Order/Breadth First Search (using queue)**

## **[Video Reference](https://youtu.be/vQIiUWofWw8)**

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
     case 9:
           cout<<"The Binary Tree in Level Order/Breadth First Search (using Queue) is  ";
           bt.printLevelOrderQueue(bt.root);
           break;

// START 9 - Print Level Order/Breadth First Search (using queue)
void printLevelOrderQueue(Node* r){
    if(r==NULL)
        return;
    
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* Node=q.front();
        q.pop();
        if(Node != NULL){
            cout<<Node->data<<" ";// print the current node value
            if(Node->left != NULL)
                 q.push(Node->left);// enqueue the left child
            if(Node->right != NULL)
                  q.push(Node->right);// enqueue the right child
        }
    }
}
// END 9 - Print Level Order/Breadth First Search (using queue)

```

<hr>

## **10 - Print Level Order/Breadth First Search (using Recursion)**

## **[Video Reference](https://youtu.be/EEm_d8WbXjs)**

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
    case 10:
           cout<<"The Binary Tree in Level Order/Breadth First Search (using Recursion) is = "<<endl;
           bt.printLevelOrderRecursion(bt.root);
           break;

// START 10 - Print Level Order/Breadth First Search (using Recursion)
void printLevelOrderRecursion(Node* r) {
		int h = Height(r);
		for (int i = 0; i <= h; i++)
			printGivenLevel(r, i); //here i means we r passing level
	}
// END 10 - Print Level Order/Breadth First Search (using Recursion)

```

<hr>

## **11 - Print Given Level of the Tree**

## **[Video Reference](https://youtu.be/EEm_d8WbXjs)**

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
    case 11:
           int l;
           cout<<"Enter the Level to print Level Order: ";
           cin>>l;
           cout<<"The Nodes in Level-" <<l <<" in Level Order are: ";
           bt.printGivenLevel(bt.root,l);
            break;

// START 11 - Print Given Level of the Tree
    void printGivenLevel(Node* r,int level){  
		if (r == NULL) // base case
			return;
		else if (level == 0)
			cout<<r->data <<" ";
		else { // level > 0
			printGivenLevel(r->left, level - 1);
			printGivenLevel(r->right, level - 1);
		}
	}
// END 11 - Print Given Level of the Tree

```
<hr>

## **12 - Sum of values at level K**

## **[Video Reference](https://www.youtube.com/watch?v=jkxZySeOPgk)**

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
    case 12:
           int k;
           cout<<"Enter level(K) : ";
           cin>>k;
           bt.sum=0;
           cout<<"Sum of values at level " << k<<" is = "<<bt.sumAtK(bt.root,k)<<endl;
           break;

// START 12 - Sum of values at level K
    int sum = 0;
    int sumAtK(Node* r, int K){
		if (r == NULL)
			return sum;
		else if (K == 0) // if K is at root level (0)
			sum = sum + r->data;
		else{
			sumAtK(r->left, K - 1);
			sumAtK(r->right, K - 1);
		}
		return sum;
	}
// END 12 - Sum of values at level K
```
<hr>

## **13 - Print Pre-Order Traversal (NODE, LEFT, RIGHT)**

## **[Video Reference](https://youtu.be/Pj5w6qnCXes)**

![Pre-Order Traversal Pseudocode](https://i.ibb.co/Dz3mVrv/preorder.png)

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
    case 13:
            cout<<"The Tree Nodes in Pre-Order Fashion (NODE, LEFT, RIGHT): ";
            bt.printPreOrder(bt.root);
            break;

// START 13 - Print Pre-Order Traversal (NODE, LEFT, RIGHT)
void printPreOrder(Node* r) { // N L R
      if(r==NULL)
          return;
      cout<<r->data;
      printPreOrder(r->left);
      printPreOrder(r->right);
}
// END 13 - Print Pre-Order Traversal

```

<hr>

## **14 - Print In-Order Traversal (LEFT, NODE, RIGHT)**

## **[Video Reference](https://www.youtube.com/watch?v=KIVdqquGehY)**

![In-Order Traversal Pseudocode](https://i.ibb.co/nDmK5q2/inorder.png)

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
    case 14:
            cout<<"The Tree Nodes in In-Order Fashion (LEFT, NODE, RIGHT): ";
            bt.printInOrder(bt.root);
            break;

// START 14 - Print In-Order Traversal (LEFT, NODE, RIGHT)
    void printInOrder(Node* r) { // L N R
         if(r==NULL)
           return;
         printInOrder(r->left);
         cout<<r->data;
         printInOrder(r->right);
}
// END 14 - Print In-Order Traversal


```

<hr>

## **15 - Print Post-Order Traversal (LEFT, RIGHT, NODE)**

## **[Video Reference](https://www.youtube.com/watch?v=fC3s5Pj2KuE)**

![Post-Order Traversal Pseudocode](https://i.ibb.co/841kbrF/postorder.png)

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
        case 14:
            cout<<"The Tree Nodes in In-Order Fashion (LEFT, NODE, RIGHT): ";
            bt.printInOrder(bt.root);
            break;

// START 15 - Print Post-Order Traversal (LEFT, RIGHT, NODE)
void printPostOrder(Node* r){
    if(r==NULL)
       return;
    printPostOrder(r->left);
    printPostOrder(r->right);
    cout<<r->data;
}
// END 15 - Print Post-Order Traversal

```

<hr>

## **16 - Print all Paths from Root to Leaf Nodes**

## **[Video Reference](https://youtu.be/zIkDfgFAg60)**

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
    case 16:
	        cout<<"All Paths from Root to Leaf Nodes are : "<<endl;
	        bt.rootToLeaf(bt.root);
	        break;

// START 16 - Print all Paths from Root to Leaf Nodes
void PrintStack(stack<int> st){
    if (st.empty())
        return;
    int x = st.top();
    st.pop();
    // cout << x << ' ';  // to print all Paths from leaf to node
    PrintStack(st);
    cout << x << ' ';
    st.push(x);
}
stack<int>st;
// print from root to leaf node by In-Order Traversal
void rootToLeaf(Node* r) {
		if (r == NULL)
			  return;
        st.push(r->data);
        rootToLeaf(r->left);
        if(r->left==NULL && r->right==NULL){ // if the encountered node is a leaf node we'll print the Path
            PrintStack(st);
            //cout<<r->data;  // to print leaf node from left to right
            cout<<endl;
        }
        rootToLeaf(r->right);
		st.pop();
}
// END 16 - Print all Paths from Root to Leaf Nodes

```

<hr>

## **17 - Search in Binary Search Tree (Iterative Approach)**

## **[Video Reference](https://youtu.be/adBuxEjVwYk)**

![](https://i.ibb.co/h7FdKrf/searchiterative.png)

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
    case 17:
            cout<<"Enter the Value to Search : ";
            cin>>val;
            if(bt.iterativeSearch(val)!=NULL)
                cout<<"Value Found";
            else //(bt.iterativeSearch(val)==NULL)
                cout<<"Value Not found";
            break;

// 	START 17 - Search in Binary Search Tree(Iterative Approach)
Node* iterativeSearch(int val){
    if(root==NULL)
         return root;

    else {
        Node* temp=root;
        while(temp!=NULL){
            if(val==temp->data) // if the node is found
                return temp;
            else if(val<temp->data)  // traverse to the left-subtree
                temp=temp->left;
            else if(val>temp->data)  // traverse to the right-subtree
                temp=temp->right;
        }
    }
}        
// 	END 17 - Search in Binary Search Tree(Iterative Approach)
```

<hr>

## **18 - Search in Binary Search Tree (Recursive Approach)**

## **[Video Reference](https://youtu.be/kU9Lv3e_kxs)**

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
        case 18:
            cout<<"Enter the Value to Search : ";
            cin>>val;
            if(bt.recursiveSearch(bt.root,val)!=NULL)
                cout<<"Value Found";
            else //(bt.recursiveSearch(bt.root,val)==NULL)
                cout<<"Value Not found";
            break;

// 	START 18 - Search in Binary Search Tree(Recursive Approach)
Node* recursiveSearch(Node* r, int val){
    if(r==NULL){
        return r;
    }
    if(val==r->data)
        return r;
    else if(val < r->data)
        return recursiveSearch(r->left,val);
    else if(val > r->data)
        return recursiveSearch(r->right,val);
}
// 	END 18 - Search in Binary Search Tree(Recursive Approach)
```

<hr>

## **19 - Diameter of Binary Tree (O(n^2) Approach)**

## **[Video Reference](https://youtu.be/S0Bwgtn32uI)**

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
        case 19:
             cout<<"Diameter of Binary Tree (O(n^2) Approach) is = " <<bt.diameterOfBT(bt.root);
             break;

// START 19 - Diameter of Binary Tree (O(n^2) Approach)
int diameterOfBT(Node* r){
    if(r==NULL)
        return 0;
    // maximum distance between two nodes of LHS (factor 1)
    int leftDiameter=diameterOfBT(r->left);
    // maximum distance between two nodes of RHS (factor 2)
    int rightDiameter=diameterOfBT(r->right);
    // maximum distance between left's deepest & right's deepest nodes (factor 3)
    int dis=Height(r->left) + Height(r->right) +2; // 2 becoz the LH and RH is 1 node  after root so al together 2

    int dia =max(dis,max(leftDiameter,rightDiameter));
    return dia;
}
// END 19 - Diameter of Binary Tree (O(n^2) Approach)

```

<hr>

## **20 - Diameter of Binary Tree (O(n) Approach)**

## **[Video Reference](https://youtu.be/Rezetez59Nk)**

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
        case 20:
             cout<<"Diameter of Binary Tree (O(n) Approach) is = "<<bt.diameterOfBinaryTree(bt.root);
             break;

// START 20 - Diameter of Binary Tree (O(n) Approach)
int height(Node* r, int& diameter){ // to call height O(n)
      if(r==NULL) {
            return 0;
        }
        int lh = height(r->left, diameter);
        int rh = height(r->right, diameter);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
 }
 int diameterOfBinaryTree(Node* Node){
     int diameter = 0;
     height(root, diameter);
    return diameter;
 }
// END 20 - Diameter of Binary Tree (O(n) Approach)

```

<hr>

## **21 - Delete a Node**

## **[Video Reference](https://youtu.be/5_AZcOOc-kM)**

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
        case 21:
             cout<<"Enter Value to Delete: ";
             cin>>val;
             bt.Delete(bt.root,val);
             break;

//	START 21 - Delete a Node
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
        if(node->left != NULL && node->right != NULL) // if the node has a left and right child
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
    return node;
}
// END 21 - Delete a Node

```

<hr>

## **22 - Construct BT from Pre-Order and In-Order**

## **[Video Reference](https://youtu.be/oAbSNJ35qAs)**

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
        case 22:   {   
            cout<<"Enter Number of Nodes in Binary Tree: ";
            cin>>val;
            
            vector<int> preorder(val);
	        vector<int> inorder(val);

            cout<<"Enter Values in Pre-Order Sequence:\n";
            for (int i = 0; i < preorder.size(); i++){
                 cout<<" ";
                 cin>>preorder[i];
            }
            cout<<"Enter Values in In-Order Sequence:\n";
            for (int i = 0; i <inorder.size(); i++){
                 cin>>inorder[i];
            }

             cout<<"-------------PRE-ORDER--------------\n";
            for (int i = 0; i < preorder.size(); i++){
                 cout<<preorder[i]<<" ";
            }
             cout<<"\n--------------IN-ORDER--------------\n";
            for (int i = 0; i <inorder.size(); i++){
                 cout<<inorder[i]<<" ";
            }
             bt.root=bt.buildTreeFromInorderPreorder(preorder,inorder);
            }
             break;

            
// START 22 - Construct BT from Pre-Order and In-Order
Node* buildTreeFromInorderPreorder(vector<int>& preorder, vector<int>& inorder){
        int n = inorder.size();
		cout<<"\nYour BT is Ready PRESS 4 AND ENTER to View";
		return preInTree(preorder, 0, n - 1, inorder, 0,n - 1);
}
        //  preS = preorder starting index
	//  preE= preorder ending index.
	//  inS= inorder starting index
	//  inE= inorder ending inex.
Node* preInTree(vector<int>& pre, int preS, int preE, vector<int>& in, int inS, int inE){
		if (inS > inE)
			return NULL;

		Node* n = new Node(pre[preS]);
		int idx = inS;
		while (in[idx] != pre[preS]){
			idx++;
        }
		int tnel = idx - inS; // total no. of element on left side/right side of root.

		n->left = preInTree(pre, preS + 1,preS + tnel, in, inS, idx - 1);
		n->right = preInTree(pre, preS + tnel + 1, preE, in, idx + 1, inE);

		return n;
}

// END 22 - Construct BT from Pre-Order and In-Order

```

<hr>

## **23 - Construct BT from Post-Order and In-Order**

## **[Video Reference](https://youtu.be/Lc3RBGtyn7M)**

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
    case 23: {
            cout<<"Enter Number of Nodes in Binary Tree: ";
            cin>>val;
            
            vector<int> postorder(val);
	        vector<int> inorder(val);

            cout<<"Enter Values in Post-Order Sequence:\n";
            for (int i = 0; i < postorder.size(); i++){
                 cout<<" ";
                 cin>>postorder[i];
            }
            cout<<"Enter Values in In-Order Sequence:\n";
            for (int i = 0; i <inorder.size(); i++){
                 cin>>inorder[i];
            }

             cout<<"-------------POST-ORDER--------------\n";
            for (int i = 0; i < postorder.size(); i++){
                 cout<<postorder[i]<<" ";
            }
             cout<<"\n--------------IN-ORDER--------------\n";
            for (int i = 0; i <inorder.size(); i++){
                 cout<<inorder[i]<<" ";
            }
             bt.root=bt.buildTreeFromInorderPostorder(postorder,inorder);
            }
             break;

// START 23 - Construct BT from Post-Order and In-Order
Node* buildTreeFromInorderPostorder(vector<int>& postorder, vector<int>& inorder){
        int n = postorder.size();
		cout<<"\nYour BT is Ready PRESS 4 AND ENTER to View";
		return postInTree(postorder, 0, n - 1, inorder, 0,n - 1);
}
        //  poS = postorder starting index
	//  poE= postorder ending index.
	//  inS= inorder starting index
	//  inE= inorder ending inex.
Node* postInTree(vector<int>& post, int poS, int poE, vector<int>& in, int inS, int inE) {
		if (inS > inE)
			return NULL;
		Node* n = new Node(post[poE]);
		int idx = inS;
		while (in[idx] != post[poE])
			idx++;
		int tnel = idx - inS; // total no of elements on left side/right side of root.

		n->left = postInTree(post, poS, poS + tnel - 1, in, inS, idx - 1);
		n->right = postInTree(post, poS + tnel, poE - 1, in, idx + 1, inE);

		return n;
	}
// END 23 - Construct BT from Post-Order and In-Order
```

<hr>

## **24 - Construct BST from In-Order**

## **[Video Reference](https://youtu.be/UAsLKuEMhsQ)**

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
        case 24: {
            cout<<"Enter Number of Nodes in Binary Tree: ";
            cin>>val;

             vector<int> inorder(val);

            cout<<"Enter Values in In-Order Sequence:\n";
            for (int i = 0; i <inorder.size(); i++){
                 cin>>inorder[i];
            }
            cout<<"\n--------------IN-ORDER--------------\n";
            for (int i = 0; i <inorder.size(); i++){
                 cout<<inorder[i]<<" ";
            }
            bt.root=bt.buildBSTfromInorder(inorder);
            }
            break;

// START 24 - Construct BST from In-Order
Node* buildBSTfromInorder(vector<int>& inorder) {
		int n = inorder.size();
		cout<<"\nYour BT is Ready PRESS 4 AND ENTER to View";
		return buildBSTfrom_Inorder(inorder, 0, n - 1);
	}

Node* buildBSTfrom_Inorder(vector<int>& in, int start, int end) {
		if (start > end)
			return NULL;
		int midRoot = (start + end) / 2;
		Node* n = new Node(in[midRoot]);

		n->left = buildBSTfrom_Inorder(in, start, midRoot - 1);
		n->right = buildBSTfrom_Inorder(in, midRoot + 1, end);

		return n;
	}
// END 24 - Construct BST from In-Order
```

<hr>

## **25 - Construct BST from Pre-Order**

## **[Video Reference](https://youtu.be/Bexswo4pqZQ)**

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
        case 25: {
            cout<<"Enter Number of Nodes in Binary Tree: ";
            cin>>val;

             vector<int> preorder(val);

            cout<<"Enter Values in Pre-Order Sequence:\n";
            for (int i = 0; i <preorder.size(); i++){
                 cin>>preorder[i];
            }
            cout<<"\n--------------PRE-ORDER--------------\n";
            for (int i = 0; i <preorder.size(); i++){
                 cout<<preorder[i]<<" ";
            }
            bt.root=bt.buildBSTfromPreorder(preorder);
            }
            break;
    
// START 25 - Construct BST from Pre-Order
int idx = 0;
Node* buildBSTfromPreorder(vector<int>& preorder) {
        int lr = -1000; // left range
		int rr = 1000; // right range
		idx = 0;
        cout<<"\nYour BT is Ready PRESS 4 AND ENTER to View";	
        return buildBSTfrom_Preorder(preorder, lr, rr);
	}

Node* buildBSTfrom_Preorder(vector<int>& pre, int lr, int rr) {
    if (idx >= pre.size() || pre[idx] < lr || pre[idx] > rr)
			return NULL;

		Node* n = new Node(pre[idx++]);

		n->left = buildBSTfrom_Preorder(pre, lr, n->data);
		n->right = buildBSTfrom_Preorder(pre, n->data, rr);

		return n;	
	}
// END 25 - Construct BST from Pre-Order
```

<hr>

## **26 - Construct BST from Post-Order**

## **[Video Reference](https://youtu.be/KsGXE7_y2Nw)**

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
        case 26: {
            cout<<"Enter Number of Nodes in Binary Tree: ";
            cin>>val;
            
            vector<int> postorder(val);

            cout<<"Enter Values in Post-Order Sequence:\n";
            for (int i = 0; i < postorder.size(); i++){
                 cout<<" ";
                 cin>>postorder[i];
            }
            cout<<"-------------POST-ORDER--------------\n";
            for (int i = 0; i < postorder.size(); i++){
                 cout<<postorder[i]<<" ";
            }
            bt.root=bt.buildBSTfromPostorder(postorder);
            }
            break;

// START 26 - Construct BST from Post-Order
Node* buildBSTfromPostorder(vector<int>& postorder){
        int lr = -1000; // left range
		int rr = 1000; // right range
		idx = postorder.size() - 1;
        cout<<"\nYour BT is Ready PRESS 4 AND ENTER to View";	
        return buildBSTfrom_Postorder(postorder, lr, rr);
}
Node* buildBSTfrom_Postorder(vector<int>&post, int lr, int rr) {
		if (idx < 0 || post[idx] < lr || post[idx] > rr)
			return NULL;

		Node* n = new Node(post[idx--]);

		n->right = buildBSTfrom_Postorder(post, n->data, rr);
		n->left = buildBSTfrom_Postorder(post, lr, n->data);

		return n;
}
// END 26 - Construct BST from Post-Order

```

<hr>

## **27 - Check if the Binary Tree is Balanced**

## **[Video Reference](https://www.youtube.com/watch?v=lUDgp2D6sf8)**

```cpp
// main fun calling
    BST bt; // BST is a class that contains all functions
        case 27:
              bt.height(bt.root);
              cout<<bt.isBal;
              break;

// START 27 - Check if the Binary Tree is Balanced
// Return true if difference between heights is not more than 1 and left and right subtrees 
// are balanced, otherwise return false. 

bool isBal = true; // exclusive for func 27
    int height(Node* r) {
		if (r == NULL)
			return -1;

		else {
			int lheight = height(r->left);
			int rheight = height(r->right);

			// exclusive for function 27, ignore this condition for finding the height
			if (abs(lheight - rheight) > 1) {
				isBal = false;
			}
			return max(lheight, rheight) + 1;
		}
	}
// END 27 - Check if the Binary Tree is Balanced
```
<hr>


<hr>

<h1 align="center"><b><a href="./BinarySearchTree.cpp">SEE MY FULL IMPLEMENTED CODE HERE</a></b></h1>

<h1 align="center"><b>THANK YOU</b></h1>
