# Best Time to Buy and Sell Stock

## Company
Amazon D-E-Shaw Directi Flipkart Goldman Sachs Intuit MakeMyTrip Microsoft 

## Link
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

## Question
#### You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.


Examples:
```
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
```
```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
```
```

```

## Solution

### 1. Approach
Keep track of the minimum price so far.

At each step, calculate the potential profit if we sell today.

Keep updating the maximum profit.

```cpp
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

```
### 2. 

```cpp


```