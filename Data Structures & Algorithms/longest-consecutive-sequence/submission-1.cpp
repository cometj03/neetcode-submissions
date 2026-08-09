class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> S(nums.begin(), nums.end());
        int ans = 0;
        for (int n : S) {
            if (S.contains(n - 1)) continue;
            int length = 1;
            while (S.contains(n + length)) length++;
            ans = max(ans, length);
        }
        return ans;
    }
};
