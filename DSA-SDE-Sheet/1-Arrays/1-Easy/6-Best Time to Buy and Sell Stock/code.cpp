#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices){
    int maxProfit = 0;

    // Minimum price so far
    int minimumPrice = prices[0];

    for(int i = 1; i < prices.size(); i++){

        // The potential profit if we sell today
        int currentProfit = prices[i] - minimumPrice;

        // Updating the maximum profit
        maxProfit = max(maxProfit, currentProfit);

        // Keeping track of the minimum price
        minimumPrice = min(minimumPrice, prices[i]); 
    }

    return maxProfit;
}

int main(){

}