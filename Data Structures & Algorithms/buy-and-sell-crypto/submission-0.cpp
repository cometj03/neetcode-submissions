class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, N = prices.size();
        vector<int> maxPrice(N, 0);
        maxPrice[N - 1] = prices[N - 1];
        for (int i = N - 2; i >= 0; i--) maxPrice[i] = max(maxPrice[i + 1], prices[i]);
        for (int i = 0; i < N; i++) ans = max(ans, maxPrice[i] - prices[i]);
        return ans;
    }
};
