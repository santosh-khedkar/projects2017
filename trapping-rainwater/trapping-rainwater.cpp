/*Array denotes the height (in units) of the building. 
Find the amount of water stored in between*/

#include <iostream>
#include <climits>

using namespace std;

int trapped_rainwater(int building[], int n){
	int left = 0, right = n-1;
	int lmax = INT_MIN, rmax = INT_MIN;
	int trapped_water = 0;

	while (left <= right){
		if (building[left] < building[right]){
			if (building[left] > lmax){
				lmax = building[left];
			}
			else {
				trapped_water = trapped_water + lmax - building[left];
			}
			left++;
		}
		else {
			if (building[right] > rmax){
				rmax = building[right];
			}
			else{
				trapped_water = trapped_water + rmax - building[right];
			}
			right--;
		}
	}
	return trapped_water;
}


int main() {
	
	int building[7] = {3, 5, 7, 2, 3, 6, 4};

	cout << "Amount of water that will be trapped is: " << trapped_rainwater(building, 7)<<endl;

	return 0;
}