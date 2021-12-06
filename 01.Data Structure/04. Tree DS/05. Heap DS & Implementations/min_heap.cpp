
#include <bits/stdc++.h>
using namespace std;

class Min_Heap{
    public:
    int* hArr; // pointer to array of elements in heap
    int hcap; // maximum possible size of min heap
    int h_size; // Current number of elements in min heap

    Min_Heap(){
        hcap=0;
        h_size=0;
        hArr=new int[hcap];
    }
    
    Min_Heap(int cap){
        hcap=cap;
        h_size=0;
        hArr=new int[hcap];
    }
    
    int parent(int i) {
		return (i - 1) / 2;
    }

    int left(int i) {
        return (2 * i + 1);
    }

    int right(int i) {
        return (2 * i + 2);
    }

    int getMin() {
        return hArr[0];
    }

// A utility function to swap two elements
    void swap(int currI, int swI) { // currentIndex, swapIndex
		int temp = hArr[currI];
		hArr[currI] = hArr[swI];
		hArr[swI] = temp;
    }

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

// START 2 - Display the Heap
    void displayArray() {
    for (int i = 0; i < h_size; i++)
      cout << hArr[i] << " ";
    cout << endl;
    }
// END 2 - Display the Heap

// START 3 - Height of Heap tree
int height() {
    return ceil(log2(h_size + 1)) - 1;
  }
// END - Height of Heap tree

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
    
// START 7 - Heap Sort
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

};

int main(){
  
  int hcapacity,option;
  cout << "Enter Heap Capacity:" << endl;
  cin >> hcapacity; // 5
  Min_Heap hp(hcapacity);
  int val=0;

  do{
        cout<<endl; 
        cout<<"0 - Exit"<<endl;   
        cout<<"1 - Insert an Element"<<endl;
        cout<<"2 - Display the Heap"<<endl;
        cout<<"3 - Height of the Heap"<<endl;
        cout<<"4 - Current Heap Size"<<endl;
        cout<<"5 - minExtract()"<<endl;
        cout<<"6 - Delete Key"<<endl;
        cout<<"7 - Heap Sort"<<endl;
        cout<<"8 - Linear Search"<<endl;  
        cout<<"*********************************************************************"<<endl;
        cout<<"Enter the option: ";
        
        cin>>option;
        switch(option){
            case 0:
		break;

	    case 1:
		cout<<"Enter Value to be Inserted: "<<endl;
		cin>>val;
		hp.insert(val);
		break;

	    case 2:
		hp.displayArray();
		break;

            case 3:
                cout<<"Height is - "<<hp.height();
                break;

            case 4:
                cout<<"The Size of the Heap is = "<<hp.h_size;
                break;
            
            case 5:
                cout<<hp.minExtract();
                break;

            case 6:
                cout<<"Enter Key to be Deleted: ";
                cin>>val;
                hp.minDeleteKey(val);
                break;
            
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

            case 8:
                cout << "SEARCH Operation -" << endl;
                cout << "Enter VALUE to SEARCH in HEAP: ";
                cin >> val;
                hp.linearSearch(val);
                break;
			
            default:
                cout<<"INVALID CHOICE";
    } 
  }while (option !=0);
    return 0;
}
