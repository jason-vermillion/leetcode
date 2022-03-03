// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPrice = 0;
        int maxProfit = 0;
        int sz = prices.size();
        
        for (int i = sz - 1; i >= 0; --i) {
            maxPrice = max(maxPrice, prices[i]);
            int currProfit = maxPrice - prices[i];
            maxProfit = max(currProfit, maxProfit);
        }
        
        return maxProfit;
    }
};