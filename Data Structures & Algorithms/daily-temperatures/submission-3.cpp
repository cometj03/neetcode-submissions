class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        vector<int> DP(temps.size(), 0);
        for (int i = temps.size() - 2; i >= 0; i--) {
            int j = i + 1;
            while (j < temps.size() && temps[j] <= temps[i]) {
                if (DP[j] == 0) {
                    j = temps.size();
                    break;
                }
                j += DP[j];
            }
            if (j < temps.size()) DP[i] = j - i;
        }
        return DP;
    }
};
