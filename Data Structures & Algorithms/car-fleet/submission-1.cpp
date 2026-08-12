class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int N = position.size(), ret = 0;
        vector<pair<int, int>> cars;
        for (int i = 0; i < N; i++) cars.emplace_back(position[i], speed[i]);
        sort(cars.begin(), cars.end());

        while (!cars.empty()) {
            auto [pos, speed] = cars.back(); cars.pop_back();
            int dist = target - pos;
            while (!cars.empty()) {
                auto [back_pos, back_speed] = cars.back();
                int back_dist = target - back_pos;
                if (back_dist * speed > dist * back_speed) break;
                cars.pop_back();
            }
            ret++;
        }
        return ret;
    }
};
