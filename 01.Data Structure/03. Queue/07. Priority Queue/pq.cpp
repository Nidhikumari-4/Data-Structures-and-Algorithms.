#include <bits/stdc++.h>
using namespace std;

int H[50];
int size = -1;

int parent(int i){
	return (i - 1) / 2;
}

int leftChild(int i){
	return ((2 * i) + 1);
}

int rightChild(int i){
	return ((2 * i) + 2);
}

//to get value of the current maximum element
int getMax(){
	return H[0];
}

// to shift up the node in order
void shiftUp(int i){
	while (i > 0 && H[parent(i)] < H[i]) {

		// Swap parent and current node
		swap(H[parent(i)], H[i]);
		// Update i to parent of i
		i = parent(i);
	}
}

// to shift down the node in
void shiftDown(int i){
	int largest = i;
	int r = rightChild(i);
	int l = leftChild(i);

	if (l <= size && H[l] > H[largest]) {
		largest = l;
	}
	if (r <= size && H[r] > H[largest]) {
		largest = r;
	}
	// If i not same as maxIndex
	if (i != largest) {
		swap(H[i], H[largest]);
		shiftDown(largest);
	}
}

// insert a new element
void insert(int val){
	size = size + 1;
	H[size] = val;

	// Shift Up to maintain heap property
	shiftUp(size);
}

// extract the element with
// maximum priority
int extractMax(){
	int result = H[0];

	// Replace the value at the root
	// with the last leaf
	H[0] = H[size];
	size = size - 1;

	// Shift down the replaced element
	// to maintain the heap property
	shiftDown(0);
	return result;
}

// change the priority
void changePriority(int i, int p){
	int oldp = H[i];
	H[i] = p;

	if (p > oldp) {
		shiftUp(i);
	}
	else {
		shiftDown(i);
	}
}

// to remove the element located at given index
void remove(int i)
{
	H[i] = getMax() + 1;

	// Shift the node to the root
	shiftUp(i);

	// Extract the node
	extractMax();
}

// Driver Code
int main()
{

	/*		  45
			 /	 \
		   31	  14
		   / \    / \
		  13 20  7   11
		  / \
	    12   7
	Create a priority queue shown in
	example in a binary max heap form.
	Queue will be represented in the
	form of array as:
	45 31 14 13 20 7 11 12 7 */

	insert(45);
	insert(20);
	insert(14);
	insert(12);
	insert(31);
	insert(7);
	insert(11);
	insert(13);
	insert(7);

	int i = 0;

	// Priority queue before extracting max
	cout << "Priority Queue : ";
	while (i <= size) {
		cout << H[i] << " ";
		i++;
	}

	cout << "\n";

	// Node with maximum priority
	cout << "Node with maximum priority : "
		<< extractMax() << "\n";

	// Priority queue after extracting max
	cout << "Priority queue after "
		<< "extracting maximum : ";
	int j = 0;
	while (j <= size) {
		cout << H[j] << " ";
		j++;
	}

	cout << "\n";

	// Change the priority of element
	// present at index 2 to 49
	changePriority(2, 49);
	cout << "Priority queue after "
		<< "priority change : ";
	int k = 0;
	while (k <= size) {
		cout << H[k] << " ";
		k++;
	}

	cout << "\n";

	// Remove element at index 3
	remove(3);
	cout << "Priority queue after "
		<< "removing the element : ";
	int l = 0;
	while (l <= size) {
		cout << H[l] << " ";
		l++;
	}
	return 0;
}
