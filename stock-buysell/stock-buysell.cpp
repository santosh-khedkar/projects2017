/*Given a array of stock prices, find the indexes 
at which you should buy and sell to get max profit*/

#include <iostream>
#include <cstdlib>


using namespace std;

struct stock {
	int buy;
	int sell;
};


stock * find_maxprofit(int stock_price[], int n){
	int max_profit = 0, profit;
	int buy = 0;
	stock *node1 = (stock *)malloc(sizeof(stock));

	for (int i = 1 ; i < n ; i++){
		profit = stock_price[i] - stock_price[buy];
		if (max_profit < profit){
			max_profit = profit;
			node1->buy = buy;
			node1->sell = i;
		}
		if (stock_price[buy] > stock_price[i]){
			buy = i;
		}
	}
	return node1;
}

int main() {

	int stock_price[10] = {23, 13, 25, 29, 33, 19, 34, 45, 65, 67};

	stock *node1 = find_maxprofit(stock_price, 10);

	cout << "The stock should be bought on day: "<< node1->buy << " and sold on day: " << node1->sell << " ";
	cout << "For a profit of : " << stock_price[node1->sell] - stock_price[node1->buy]<<endl; 

	return 0;
}