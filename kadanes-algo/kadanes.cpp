/* Given array of integers, find the maximum sum contiguous array
*/

#include <iostream>
#include <climits>

using namespace std;

int max_contiguos_sum(int arr[], int n) {
	int max_so_far = INT_MIN;
	int curr_sum = 0;

	for (int i = 0; i < n; i++){
		curr_sum = curr_sum + arr[i];

		if (max_so_far < curr_sum){
			max_so_far = curr_sum;
		}
		if (curr_sum < 0){
			curr_sum = 0;
		}
	}
	return max_so_far;
}

int main(){
	int arr[10] = {-1, 2, 3, -10, 15, 50, -15, 12, 54,-30};
	
	cout << "Max continguos sum: "<< max_contiguos_sum(arr, 10)<<endl;
	
	return 0 ;
}