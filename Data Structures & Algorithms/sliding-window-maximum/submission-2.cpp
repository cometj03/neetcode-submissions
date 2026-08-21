class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> Q; // <value, index>
        vector<int> ans;
        for (int i = 0; i < k; i++) Q.emplace(nums[i], i);
        ans.push_back(Q.top().first);

        for (int l = 1, r = k; r < nums.size(); l++, r++) {
            Q.emplace(nums[r], r);
            while (Q.top().second < l) Q.pop();
            ans.push_back(Q.top().first);
        }
        return ans;
    }
};
