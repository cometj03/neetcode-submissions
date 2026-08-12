class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> ss;
        for (char c : s) {
            if ('A' <= c && c <= 'Z') ss.push_back(c - 'A' + 'a');
            if ('a' <= c && c <= 'z' || '0' <= c && c <= '9') ss.push_back(c);
        }
        int i = 0, j = ss.size() - 1;
        while (i < j) {
            if (ss[i] != ss[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
