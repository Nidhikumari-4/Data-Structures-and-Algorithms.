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

    case 11:
           int l;
           cout<<"Enter the Level to print Level Order: ";
           cin>>l;
           cout<<"The Nodes in Level-" <<l <<" in Level Order are: ";
           bt.printGivenLevel(bt.root,l);
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

