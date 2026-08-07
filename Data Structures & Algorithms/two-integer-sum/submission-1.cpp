class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idx;
        for (int i = 0; i < nums.size(); i++) idx[nums[i]] = i;
        for (int i = 0; i < nums.size(); i++) {
            if (int n = target - nums[i]; idx.contains(n) && idx[n] != i) {
                if (idx[n] > i) return {i, idx[n]}; 
                else return {idx[n], i};
            }
        }
        return {-1, -1};
    }
};
