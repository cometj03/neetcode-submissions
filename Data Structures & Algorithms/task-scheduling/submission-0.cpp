class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int count[26] = {0};
        priority_queue<int> Q;
        queue<pair<int, int>> wait;

        for (char c : tasks) count[c - 'A']++;
        for (int i = 0; i < 26; i++) {
            if (count[i]) Q.push(count[i]);
        }
        int ans = 0;
        for (; !Q.empty() || !wait.empty(); ans++) {
            if (!Q.empty()) {
                int cnt = Q.top(); Q.pop();
                if (cnt > 1) wait.push({cnt - 1, ans});
            }
            while (!wait.empty() && ans - wait.front().second >= n) {
                Q.push(wait.front().first);
                wait.pop();
            }
        }
        return ans;
    }
};
