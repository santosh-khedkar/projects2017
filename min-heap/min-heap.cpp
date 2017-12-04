#include <iostream>
#include <climits>

using namespace std;

class Minheap {
	int *harr;  /*array emulating the minheap*/
	int cap;  /*total capacity of the minheap*/
	int heap_size; /*current heap size*/

public:
	Minheap(int capacity);
	int parent (int i) {
		return (i - 1) / 2;
	}
	int left (int i){
		return (2 * i + 1);
	}
	int right (int i){
		return (2 * i + 2);
	}
	int getMin(){
		return harr[0];
	}
	void insertKey(int key);
	void deleteKey(int i);
	void decreaseKey (int i, int value);
	int extractMin();
	void MinHeapify(int i);
	void printDS();
};

void swap (int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

Minheap::Minheap(int capacity){
	cap = capacity;
	heap_size = 0;
	harr = new int [cap];
}

void Minheap::insertKey(int key){
	if (heap_size >= cap){
		cout <<"Heap at capacity"<<endl;
		return;
	}
	heap_size++;
	int i = heap_size - 1;
	harr[i] = key;

	while (i != 0 && harr[i] < harr[parent(i)]){
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

void Minheap::decreaseKey(int i, int value){
	harr[i] = value;

	while (i != 0 && harr[i] < harr[parent(i)]){
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

void Minheap::deleteKey(int i){
	decreaseKey(i, INT_MIN);
	extractMin();
}

int Minheap::extractMin(){
	if (heap_size == 0){
		cout <<"Heap is empty"<<endl;
		return INT_MAX;
	}
	if (heap_size == 1){
		heap_size--;
		return harr[0];
	}

	int root = harr[0];
	harr[0] = harr[heap_size-1];
	heap_size--;
	MinHeapify(0);
	return root;
}

void Minheap::MinHeapify(int i){
	int smallest = i;
	int l = left(i);
	int r = right(i);

	if (l < heap_size && harr[l] < harr[smallest]){
		smallest = l;
	}
	if (r < heap_size && harr[r] < harr[smallest]){
		smallest = i;
	}
	if (smallest != i){
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}

void Minheap::printDS(){
	for (int i = 0 ; i< heap_size; i++)
		cout <<harr[i] <<" ";
	cout<<endl;
}

int main(){
	Minheap mh(11);
	mh.insertKey(3);
	mh.insertKey(2);
	mh.deleteKey(1);
	mh.insertKey(15);
	mh.insertKey(5);
	mh.insertKey(4);
	mh.insertKey(45);
	mh.printDS();
	cout <<mh.extractMin() <<endl;
	cout <<mh.getMin()<<endl;
	mh.decreaseKey(2,1);
	cout<<mh.getMin()<<endl;
	mh.printDS();
	return 0;
}