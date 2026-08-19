class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        queue<int> maxQ;
        for (int i = 0; i < k; i++) {
            if (maxQ.empty() || maxQ.back() <= nums[i]) maxQ.push(nums[i]);
        }

        ret.push_back(maxQ.back());
        for (int i = k; i < nums.size(); i++) {
            if (maxQ.front() == nums[i - k]) maxQ.pop();
            if (maxQ.empty()) {
                for (int j = i - k + 1; j <= i; j++) {
                    if (maxQ.empty() || maxQ.back() <= nums[j]) maxQ.push(nums[j]);
                }
            } else if (maxQ.back() <= nums[i]) {
                maxQ.push(nums[i]);
            }
            ret.push_back(maxQ.back());
        }
        return ret;
    }
};
