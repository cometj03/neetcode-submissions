class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> M;
        for (const auto& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) count[c - 'a']++;
            string key = to_string(count[0]);
            for (int i = 1; i < 26; i++) key += ',' + to_string(count[i]);
            M[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (const auto& [_, v] : M) ans.push_back(v);
        return ans;
    }
};
