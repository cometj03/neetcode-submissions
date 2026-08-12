class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        stack<int> S;
        vector<int> ret(temps.size(), 0);
        for (int i = 0; i < temps.size(); i++) {
            while (!S.empty() && temps[S.top()] < temps[i]) {
                ret[S.top()] = i - S.top();
                S.pop();
            }
            S.push(i);
        }
        return ret;
    }
};
