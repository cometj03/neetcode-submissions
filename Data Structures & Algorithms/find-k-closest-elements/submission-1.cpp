class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int startIdx = 0;
        while (startIdx < arr.size() && arr[startIdx] < x) startIdx++;

        vector<int> ret;
        if (startIdx == 0) {
            for (int i = 0; i < k; i++) ret.push_back(arr[i]);
            return ret;
        }
        if (startIdx == arr.size()) {
            for (int i = 0; i < k; i++) ret.push_back(arr[arr.size() - k + i]);
            return ret;
        }

        int l = startIdx - 1, r = startIdx;
        while (ret.size() < k) {
            if (l >= 0 && x - arr[l] <= arr[r] - x) ret.push_back(arr[l--]);
            else ret.push_back(arr[r++]);
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};