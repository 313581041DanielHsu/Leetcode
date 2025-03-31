class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> values;
        for (int i = 0; i < weights.size() - 1; ++i) {
            values.push_back(weights[i] + weights[i + 1]);
        }

        sort(values.begin(), values.end());

        long long max_score = 0, min_score = 0;

        for (int i = 0; i < k - 1; ++i) {
            min_score += values[i];
            max_score += values[values.size() - 1 - i];
        }

        return max_score - min_score;
    }
};
