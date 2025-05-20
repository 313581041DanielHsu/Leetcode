class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;
        for (char c : s) {
            if (!stk.empty() && stk.top().first == c) {
                stk.top().second++;
                if (stk.top().second == k)
                    stk.pop();
            } else {
                stk.push({c, 1});
            }
        }
        
        string result;
        while (!stk.empty()) {
            result = string(stk.top().second, stk.top().first) + result;
            stk.pop();
        }
        return result;
    }
};
