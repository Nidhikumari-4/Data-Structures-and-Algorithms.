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

