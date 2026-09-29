class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            // Profit if we sell today
            int profit = prices[i] - minPrice;

            maxProfit = max(maxProfit, profit);

            // Update minimum buying price
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};