class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> visit(nums.size() + 1, false);
        for (int n : nums) {
            if (n > 0 && n <= nums.size()) visit[n] = true;
        }
        for (int i = 1; i < nums.size() + 1; i++) {
            if (!visit[i]) return i;
        }
        return nums.size() + 1;
    }
};