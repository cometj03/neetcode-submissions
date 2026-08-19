class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> M;
        for (char c : s1) M[c]++;
        int l = 0, r = 0;
        while (r < s2.length()) {
            if (M.find(s2[r]) == M.end()) {
                while (l < r) M[s2[l++]]++;
                l = r = r + 1;
            } else if (M[s2[r]] == 0) {
                M[s2[l]]++;
                l++;
            } else {
                M[s2[r]]--;
                r++;
            }
            cout << l << ", " << r << "\n";
            if (s1.length() == r - l) return true;
        }
        return false;
    }
};
