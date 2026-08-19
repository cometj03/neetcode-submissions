class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, N = prices.size(), maxPrice = 0;
        for (int i = N - 1; i >= 0; i--) {
            ans = max(ans, maxPrice - prices[i]);
            maxPrice = max(maxPrice, prices[i]);
        }
        return ans;
    }
};
