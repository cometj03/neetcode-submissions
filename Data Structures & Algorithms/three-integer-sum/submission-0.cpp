class Solution {
public:
    bool checkDuplicate(const vector<vector<int>>& v, const vector<int>& e) {
        for (auto& a : v) {
            if (a[0] == e[0] && a[1] == e[1] && a[2] == e[2]) return true;
        }
        return false;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < N - 2; i++) {
            int j = i + 1, k = N - 1;
            int target = -nums[i];
            while (j < k) {
                int sum = nums[j] + nums[k];
                if (sum == target) {
                    vector<int> e = {nums[i], nums[j], nums[k]};
                    if (!checkDuplicate(ans, e)) ans.push_back(e);
                    j++; k--;
                }
                else if (sum < target) j++;
                else k--;
            }
        }

        return ans;
    }
};
