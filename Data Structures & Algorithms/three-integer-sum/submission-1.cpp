class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < N - 2; i++) {
            int j = i + 1, k = N - 1;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                }
                else if (sum < 0) j++;
                else k--;
            }
        }

        return ans;
    }
};
