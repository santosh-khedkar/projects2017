#include <iostream>
#include <climits>

using namespace std;

class Minheap {
	int heap_size;
	int cap;
	int *harr;

public:
	Minheap(int cap);

	int parent (int i) { 
		return i - 1;
	}

	int left (int i) {
		return 2 * i + 1;
	}

	int right (int i) {
		return 2 * i + 2;
	}

	void decrease_key (int i, int value);
	void Minheapify(int i);
	void Insert_key(int value);
	void delete_key(int i);

	int get_min(){
		return harr[0];
	}
	int extract_min();
};

void swap (int *x , int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

Minheap::Minheap (int capacity){
	heap_size = 0;
	cap = capacity;
	harr = new int [cap];
}

void Minheap::decrease_key (int i, int value) {
	harr[i] = value;

	while (i!=0 && harr[i] < harr[parent(i)]){
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}


void Minheap::Insert_key(int value) {
	
	if(heap_size == cap){
		cout << "Heap at capacity";
		return;
	}

	int i = heap_size - 1;
	harr[i] = value;

	while (i !=0 && harr[i] < harr[parent(i)]){
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

void Minheap::delete_key(int i) {
	decrease_key(i, INT_MIN);
	extract_min();
}

int Minheap::extract_min() {
	if (heap_size == 0){
		return INT_MAX;
	}
	if (heap_size == 1){
		heap_size--;
		return harr[0];
	}

	int root = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;
	Minheapify(0);
	return root;
}

void Minheap::Minheapify(int i) {
	int l = left(i);
	int r = right(i);
	int smallest = i;

	if (l < heap_size && harr[l] < harr[smallest]){
		smallest = l;
	}
	if (r < heap_size && harr[r] < harr[smallest]){
		smallest = r;
	}
	if (smallest != i){
		swap(&harr[i], &harr[smallest]);
		Minheapify(smallest);
	}

}
int main(){
	Minheap min_heap(11);
	min_heap.Insert_key(3);
	min_heap.Insert_key(2);
	min_heap.delete_key(1);
	min_heap.Insert_key(15);
	min_heap.Insert_key(5);
	min_heap.Insert_key(4);
	min_heap.Insert_key(45);
	cout <<min_heap.extract_min() <<endl;
	cout <<min_heap.get_min()<<endl;
	min_heap.decrease_key(2,1);
	cout<<min_heap.get_min();

	return 0;
}