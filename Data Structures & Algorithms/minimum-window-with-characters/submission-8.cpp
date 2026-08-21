class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> M;
        for (char c : t) M[c]++;

        int l = 0, r = 0;
        while (r < s.length() && M.find(s[r]) == M.end()) l++, r++;

        int count = 0, need = t.length(), startIdx = -1, len = INT_MAX;

        while (r < s.length()) {
            M[s[r]]--;
            if (M[s[r]] >= 0) count++;
            while (count == need) {
                if (len > r - l + 1){
                    startIdx = l;
                    len = r - l + 1;
                }

                M[s[l]]++; // restore
                if (M[s[l]] > 0) count--;
                // 'l' to next checkpoint
                do { l++; } while (l < r && M.find(s[l]) == M.end());
            }
            // 'r' to next checkpoint
            do { r++; } while (r < s.length() && M.find(s[r]) == M.end());
        }
        return startIdx == -1 ? "" : s.substr(startIdx, len);
    }
};
