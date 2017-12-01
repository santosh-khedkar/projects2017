/*There are tasks from A-Z each task once executed need x cooldown time until it is executed again.
execution time it 1 unit. Calculate the total time*/

#include <iostream>
#include <cstring>

using namespace std;

int tot_exectime(char seq[], int exectime, int cooldown, int tot_task){
	int lastexec[26];
	int tot_time = 0, idx;
	memset (lastexec, -1, sizeof(lastexec));

	for(int i = 0 ; i < tot_task; i++){
		idx = (int)(seq[i] - 'A');
	    if (((i - 1 - lastexec[idx]) < cooldown) && lastexec[idx] != -1) {
	    	tot_time = tot_time + cooldown - (i - 1 - lastexec[idx]);
	    }
	    tot_time = tot_time + 1;
		lastexec[idx] = i;
	}
	return tot_time;
}

int main() {
	char seq [10] = {'A', 'B', 'A', 'Z', 'B', 'F', 'B', 'C', 'C', 'B'};

	cout << "Total execution time: " << tot_exectime(seq, 1, 3, 10) <<endl;

	return 0;
}