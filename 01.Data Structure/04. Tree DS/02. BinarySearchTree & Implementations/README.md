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
};
    // all above functions like insertion, deletion, printing, traversing will be here
    };

```


