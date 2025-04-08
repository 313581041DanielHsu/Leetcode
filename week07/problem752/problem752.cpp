class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // 使用集合來儲存死結
        unordered_set<string> dead(deadends.begin(), deadends.end());
        
        // 如果初始狀態就被標記為死結，則返回 -1
        if (dead.count("0000")) return -1;
        
        // BFS 队列，存儲當前狀態和步數
        queue<pair<string, int>> q;
        q.push({"0000", 0});  // 初始狀態是 "0000"，步數為 0
        
        // 訪問過的狀態
        unordered_set<string> visited;
        visited.insert("0000");
        
        // 定義一個函數來生成所有可能的下一步狀態
        auto getNextStates = [](const string& s) -> vector<string> {
            vector<string> nextStates;
            for (int i = 0; i < 4; i++) {
                for (int d = -1; d <= 1; d += 2) {  // -1 表示逆時針，+1 表示順時針
                    string next = s;
                    next[i] = (next[i] - '0' + d + 10) % 10 + '0';  // 計算下一個狀態
                    nextStates.push_back(next);
                }
            }
            return nextStates;
        };
        
        // 開始 BFS
        while (!q.empty()) {
            string curr = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            // 如果當前狀態是目標狀態，則返回步數
            if (curr == target) return steps;
            
            // 生成所有可能的下一步狀態
            vector<string> nextStates = getNextStates(curr);
            
            for (const string& next : nextStates) {
                // 如果下一個狀態不是死結且未訪問過，則加入隊列
                if (!dead.count(next) && !visited.count(next)) {
                    visited.insert(next);
                    q.push({next, steps + 1});
                }
            }
        }
        
        return -1;
    }
};
