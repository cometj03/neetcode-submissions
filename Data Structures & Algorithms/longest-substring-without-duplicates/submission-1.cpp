class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> alpha;
        int l = 0, r = 0, ans = 0;
        alpha[s[0]] = 1;
        while (r < s.length()) {
            while (l < r && alpha[s[r]]) {
                alpha[s[l]] = 0;
                l++;
            }
            ans = max(ans, r - l + 1);
            alpha[s[r]] = 1;
            r++;
        }
        return ans;
    }
};
