class Solution {
public:
    vector<vector<int>> ret;
    vector<int> tmp;

    void dfs(vector<int>& nums, int i) {
        if (i == nums.size()) {
            ret.push_back(tmp);
            return;
        }
        tmp.push_back(nums[i]);
        dfs(nums, i + 1);
        tmp.pop_back();
        dfs(nums, i + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ret;
    }
};
