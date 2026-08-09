class Solution {
public:

    string encode(vector<string>& strs) {
        string ret;
        for (string s : strs) ret += to_string(s.length()) + '#' + s;
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        int i = 0;
        while (i < s.length()) {
            int j = i;
            while (s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i));
            ret.push_back(s.substr(j + 1, len));
            i = j + len + 1;
        }
        return ret;
    }
};
