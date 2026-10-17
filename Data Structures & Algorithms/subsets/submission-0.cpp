class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        for (int n = (1 << nums.size()) - 1; n >= 0; n--) {
            vector<int> v;
            for (int i = 0; i < nums.size(); i++) {
                if ((1 << i) & n) v.push_back(nums[i]);
            }
            ret.push_back(v);
        }
        return ret;
    }
};
