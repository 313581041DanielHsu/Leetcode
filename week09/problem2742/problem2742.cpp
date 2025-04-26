class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> dp(n + 1, 1e9); // 初始設很大，因為要找最小值
        dp[0] = 0; // 0面牆花0元

        for (int i = 0; i < n; ++i) {
            for (int j = n; j >= 0; --j) {
                int next = min(n, j + time[i] + 1);
                dp[next] = min(dp[next], dp[j] + cost[i]);
            }
        }

        return dp[n];
    }
};

