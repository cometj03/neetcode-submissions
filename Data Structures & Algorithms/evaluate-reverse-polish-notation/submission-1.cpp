class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> S;
        for (string t : tokens) {
            if (t == "+") {
                int a = S.top(); S.pop();
                int b = S.top(); S.pop();
                S.push(b + a);
            } else if (t == "-") {
                int a = S.top(); S.pop();
                int b = S.top(); S.pop();
                S.push(b - a);
            } else if (t == "*") {
                int a = S.top(); S.pop();
                int b = S.top(); S.pop();
                S.push(b * a);
            } else if (t == "/") {
                int a = S.top(); S.pop();
                int b = S.top(); S.pop();
                S.push(b / a);
            } else {
                S.push(stoi(t));
            }
        }
        return S.top();
    }
};
