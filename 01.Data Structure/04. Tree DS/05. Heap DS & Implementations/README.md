# **Complete BT ?**

## Binary tree where all levels except the last are completely filled orelse if any levels are partially filled then all nodes in that level should be as left as possible.

# **HEAP DS**
## **[Video Reference](https://youtu.be/86mQ1gD3Zgg)**
<br>

## A Heap is a special Tree-based data structure in which the tree is a complete binary tree.

## It follows the Heap Property –

- ## **Max-Heap:** In a Max-Heap the key present at the root node must be greatest among the keys present at all of it’s children. The same property must be recursively true for all sub-trees in that Binary Tree.
- ## **Min-Heap:** In a Min-Heap the key present at the root node must be minimum among the keys present at all of it’s children. The same property must be recursively true for all sub-trees in that Binary Tree.
  ![](https://simplesnippets.tech/wp-content/uploads/2021/04/heap-data-structure-with-program-code.jpg)

# **WAYS OF IMPLEMENTATION**

## **[Video Reference](https://youtu.be/XWEEmITavdc)**
<br>

![](https://i.ibb.co/S7KWB3Q/HEAPdS.png)

## **NOTE:** We are going to continue with **Min Heap** implementations. For Max Heap, every approach will be as simillar as MinHeap with some small changes you yourself will know the changes once you complete MinHeap implementations.

# **Functions Overview in MinHeap**

## 1. Insertion in MinHeap

## 2. Display Heap

## 3. Height of Heap Tree

## 4. Current Heap Size

## 5. minExtract()

- Heapify

## 6. minDeleteKey()

- DecreaseKey()

## 7. Heap Sort

<hr>

# **1 - Insert an Element**

## **[Video Reference](https://youtu.be/5l3n3HFgljg)**

```cpp
//Main calling function
Min_Heap hp(hcapacity);// object of Min Heap class

    case 1:
		cout<<"Enter Value to be Inserted: "<<endl;
		cin>>val;
		hp.insert(val);
		break;

// START 1 - Insert an Element
    void insert(int val) {
        if(h_size==hcap){
            cout<<"Heap Overflow";
            return;
        }
        cout<<"Value Inserted ";
        h_size++;
        int i=h_size-1;
        hArr[i]=val;
        
        // if the new inserted node is less than its parent then swap them
        while(i != 0 && hArr[i] < hArr[parent(i)]){
            swap(i,parent(i));
            i = parent(i);
        }
    }
// END 1 - Insert an Element
```
<hr>

# **2 - Display the Heap**

```cpp
//Main calling function
Min_Heap hp(hcapacity);// object of Min Heap class

    case 2:
		hp.displayArray();
		break;

// START 2 - Display the Heap
    void displayArray() {
    for (int i = 0; i < h_size; i++)
      cout << hArr[i] << " ";
    cout << endl;
    }
// END 2 - Display the Heap

```

<hr>

# **3 - Height of the Heap**

```cpp
//Main calling function
Min_Heap hp(hcapacity);// object of Min Heap class

    case 3:
        cout<<"Height is - "<<hp.height();
        break;

// START 3 - Height of Heap tree
int height() {
    return ceil(log2(h_size + 1)) - 1;
  }
// END - Height of Heap tree
```

<hr>

# **5 - minExtract()**

## **Returning and Removing root element of Min Heap Tree** and then restructuring into Min Heap Tree this restructuring is called **Heapify.**

## **[Video Reference](https://youtu.be/AHyXBIxC63g)**

```cpp
//Main calling function
Min_Heap hp(hcapacity);// object of Min Heap class

    case 5:
        cout<<hp.minExtract();
        break;

// START 5 - minExtract()
    int minExtract() {
        if(h_size<=0){
            cout<<"Empty heap";
            return 0;
        }
        if(h_size == 1){
            h_size--;
            return hArr[0];
        }
        int root=hArr[0];
        hArr[0] = hArr[h_size - 1];
        h_size--;
        minHeapify(0);
        return root;
    }

    void minHeapify(int i){
        int l=left(i);
        int r=right(i);
        int smallest = i;

        if(l<h_size && hArr[l] < hArr[smallest])
            smallest = l;
        if(r<h_size && hArr[r] < hArr[smallest])
            smallest = r;
        if (smallest != i) {
			swap(i, smallest);
			minHeapify(smallest);
        }
    }
// END 5 - minExtract()   
```

<hr>

# **6 - Delete Key**

## This delete the key at particular index.

## **[Video Reference](https://youtu.be/aK5Qj29C5PQ)**

```cpp
//Main calling function
Min_Heap hp(hcapacity);// object of Min Heap class

  case 6:
      cout<<"Enter Key to be Deleted: ";
      cin>>val;
      hp.minDeleteKey(val);
      break;

// START 6 - Delete Key
    void minDeleteKey(int i) {
        if(i >= h_size){
            cout<<"Enter valid key";
            return;
        }
        decreaseKey(i, INT_MIN);
        minExtract();
        cout<<"Value Deleted";
    }
    // this () will set the value in deletingIndex with minimum value than will keep
	// on swapping that deletingIndex value with its parents until it reaches root
	// then minExtract() will be called to remove the root(which is
	// INT.MIN) and heapify
    void decreaseKey(int i, int minVal) {
		hArr[i] = minVal;
		while (i != 0 && hArr[i] < hArr[parent(i)]) {
			swap(i, parent(i));
			i = parent(i);
		}
	}
// END 6 - Delete Key
```

<hr>

# **7 - Heap Sort**

## **[Video Reference](https://youtu.be/XrY8z4e5HAk)**

```cpp
//Main calling function
Min_Heap hp(hcapacity);// object of Min Heap class

    case 7:
        hp.h_size=hp.hcap;
        cout<<"Enter Elements of Unsorted Array: ";
        for (int i = 0; i < hp.h_size; i++) {
				cin>>hp.hArr[i];
				}
        cout <<"No of elements to sort using HEAPSORT ";
        for (int i = 0; i < hp.h_size; i++){
            cout << hp.hArr[i]<<" ";
        }
        for (int i = hcapacity / 2 - 1; i >= 0; i--) {
        hp.minHeapify(i);
        }
				hp.heapSort();
				break;

// START 7 - Heap Sort
    case 8:
        cout << "SEARCH Operation -"endl;
        cout << "Enter VALUE to SEARCHHEAP: ";
        cin >> val;
        hp.linearSearch(val);
        break;

    void heapSort() {
        int temp[hcap];
        cout<<endl<<"After sorting elements are:";
        for (int j = 0; j < hcap; j++) {
        //cout<<minExtract()<<" ";
        temp[j] = minExtract();
        cout << temp[j] << " ";
    }
}
// END 7 - Heap Sort

```

<hr>

# **7 - Linear Search**

```cpp
Min_Heap hp(hcapacity);// object of Min Heap class
    case 8:
        cout << "SEARCH Operation -" << endl;
        cout << "Enter VALUE to SEARCH in HEAP: ";
        cin >> val;
        hp.linearSearch(val);
        break;

    //START 8 - Linear Search
    void linearSearch(int val) {
    for (int i = 0; i <= h_size; i++) {
      if (hArr[i] == val) {
        cout << "Value Found!";
         return;
      }   
    }
    cout << "Value NOT Found!";
  }
//END 8 - Linear Search
```

<h1 align="center"><b><a href="./min_heap.cpp">SEE MY FULL IMPLEMENTED CODE HERE.</a></b></h1>
<br>
<br>

<h1 align="center"><b>THANK YOU</b></h1>