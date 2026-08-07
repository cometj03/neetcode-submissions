class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> A(2020);
        for (int i = -1000; i <= 1000; i++) A[i+1000].second = i;
        for (int n : nums) A[n+1000].first++;
        sort(A.begin(), A.end());
        reverse(A.begin(), A.end());

        vector<int> ans;
        for (int i = 0; i < k; i++) ans.push_back(A[i].second);
        return ans;
    }
};
