class Solution {
public:
    bool accept(const int count[], int k) {
        int maxIdx = 0, sum = 0;
        for (int i = 0; i < 26; i++) {
            if (count[maxIdx] < count[i]) maxIdx = i;
            sum += count[i];
        }
        return sum - count[maxIdx] <= k;
    }

    int characterReplacement(string s, int k) {
        int count[26] = {0}, ans = 0;
        for (int l = 0, r = 0; r < s.length(); r++) {
            count[s[r] - 'A']++;
            if (accept(count, k)) {
                ans = max(ans, r - l + 1);
            } else {
                count[s[l] - 'A']--;
                l++;
            }
        }
        return ans;
    }
};
