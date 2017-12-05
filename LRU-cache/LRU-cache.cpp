#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
	int csize;
	list<int> dq;
	unordered_map<int,list<int>::iterator> ma;

public:
	LRUCache(int size){
		csize = size;
	}
	void refer(int x);
	void display();
};

void LRUCache::refer(int x){
	if(ma.find(x) == ma.end()){
		if (dq.size() == csize){
			int last = dq.back();
			ma.erase(last);
			dq.pop_back();
		}
	}
	else 
		dq.erase(ma[x]);
	dq.push_front(x);
	ma[x] = dq.begin();
}

void LRUCache::display(){
	for(auto it = dq.begin(); it != dq.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}

int main(){
	LRUCache lru(5);
	lru.refer(1);
	lru.refer(2);
	lru.refer(3);
	lru.refer(2);
	lru.refer(4);
	lru.refer(5);
	lru.refer(4);
	lru.refer(6);
	lru.display();
	return 0;
}