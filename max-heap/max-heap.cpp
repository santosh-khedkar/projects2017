/*Max heap implementation*/

#include <iostream>
#include <climits>

using namespace std;

class MaxHeap {
	int *harr;
	int cap;
	int heap_size;
public:
	MaxHeap(int capacity);
	int parent(int i){
		return (i - 1)/2;
	}
	int left(int i){
		return (2*i +1);
	}
	int right(int i){
		return (2*i + 2);
	}
	int getMax(){
		return harr[0];
	}
	void insertKey(int key);
	void deleteKey(int i);
	void increaseKey(int i, int value);
	int extractMax();
	void MaxHeapify(int i);
	void printDS();
};

void swap (int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

MaxHeap::MaxHeap(int capacity){
	cap = capacity;
	heap_size = 0;
	harr = new int [cap];
}

void MaxHeap::insertKey(int key){
	if (heap_size == cap){
		cout << "Heap is at capacity"<<endl;
		return;
	}
	heap_size++;
	int i = heap_size - 1;
	harr[i] = key;

	while(i != 0 && harr[i] > harr[parent(i)]){
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

void MaxHeap::increaseKey(int i , int value) {
	harr[i] = value;

	while (i != 0 && harr[i] > harr[parent(i)]){
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

void MaxHeap::deleteKey(int i){
	increaseKey(i, INT_MAX);
	extractMax();
}

int MaxHeap::extractMax(){
	if (heap_size == 0){
		cout << "Heap is empty"<<endl;
		return INT_MIN;
	}
	if (heap_size == 1){
		heap_size--;
		return harr[0];
	}
	int root = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;
	MaxHeapify(0);
	return root;
}

void MaxHeap::MaxHeapify(int i){
	int largest = i;
	int l = left(i);
	int r = right(i);

	if (l < heap_size && harr[l] > harr[largest])
		largest = l;
	if (r < heap_size && harr[r] > harr[largest])
		largest = r;
	if (largest!=i){
		swap(&harr[i],&harr[largest]);
		MaxHeapify(largest);
	}
}

void MaxHeap::printDS(){
	for (int i = 0; i< heap_size; i++){
		cout <<harr[i] <<" ";
	}
	cout <<endl;
}

int main(){
	MaxHeap mh(11);
	mh.insertKey(1);
	mh.insertKey(3);
	mh.insertKey(7);
	mh.insertKey(5);
	mh.printDS();
	cout << mh.extractMax()<<endl;
	mh.printDS();
	return 0;
}