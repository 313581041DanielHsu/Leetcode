class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        dp[0][0] = true;

        // 處理 pattern 開頭是 * 的情況
        for (int j = 1; j <= n; ++j) {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-1];
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j-1] == s[i-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }

        return dp[m][n];
    }
};

