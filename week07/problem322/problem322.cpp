class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 如果目標金額是 0，直接返回 0
        if (amount == 0) return 0;
        
        // BFS 初始化
        queue<pair<int, int>> q;  // (當前金額, 硬幣數量)
        vector<bool> visited(amount + 1, false);  // 記錄每個金額是否已經訪問過
        
        // 從金額 0 開始
        q.push({0, 0});
        visited[0] = true;
        
        while (!q.empty()) {
            int currentAmount = q.front().first;
            int numCoins = q.front().second;
            q.pop();
            
            // 嘗試每一個硬幣
            for (int coin : coins) {
                int newAmount = currentAmount + coin;
                
                // 如果找到了最少硬幣數量
                if (newAmount == amount) {
                    return numCoins + 1;
                }
                
                // 如果新金額小於 amount 且尚未訪問過
                if (newAmount < amount && !visited[newAmount]) {
                    visited[newAmount] = true;
                    q.push({newAmount, numCoins + 1});
                }
            }
        }
        
        // 如果無法湊成目標金額，返回 -1
        return -1;
    }
};
