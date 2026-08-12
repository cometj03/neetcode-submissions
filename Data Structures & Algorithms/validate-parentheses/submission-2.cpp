class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                S.push(c);
                continue;
            }
            if (c == ')' && (S.empty() || S.top() != '(')) return false;
            if (c == '}' && (S.empty() || S.top() != '{')) return false;
            if (c == ']' && (S.empty() || S.top() != '[')) return false;
            S.pop();
        }
        return S.empty();
    }
};
