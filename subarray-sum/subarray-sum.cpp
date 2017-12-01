/*Given an array of numbers find subarray which adds to a sum S*/

#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct node {
	int i,j;
};

node * find_subarr_ind(int arr[], int n, int sum){

	node *node1 = (node *) malloc(sizeof(node));
	node1->i = -1;
	node1->j = -1;
	int i = 0 , j = 0;
	int curr_sum = arr[0];

	while (i < n && j < n){
		if (curr_sum == sum){
			node1->i = i;
			node1->j = j;
			break;
		}
		else if (curr_sum < sum){
			j++;
			curr_sum = curr_sum + arr[j];
		}
		else {
			curr_sum = curr_sum - arr[i];
			i++;
		}
	}
	return node1;
}

int main() {
	int arr[10] = {-1, 2, 3, 50, 34, 23, -12, 45, -21, 20};

	node *node1 = find_subarr_ind(arr, 10, 143);
	if (node1->i == -1 && node1->j == -1){
		cout << "No sum found"<<endl;
	}
	else{
		cout << "Indices are: " <<node1->i<< " and "<<node1->j<< endl;
	}
	return 0;

}