class Solution {
public:
    string removeDuplicateLetters(string s) {
        array<int, 26> count = {0};
        vector<bool> inStack(26, false);
        stack<char> stk;

        for (char c : s) {
            count[c - 'a']++;
        }

        for (char c : s) {
            int idx = c - 'a';
            count[idx]--;

            if (inStack[idx]) continue;

            while (!stk.empty() && c < stk.top() && count[stk.top() - 'a'] > 0) {
                inStack[stk.top() - 'a'] = false;
                stk.pop();
            }

            stk.push(c);
            inStack[idx] = true;
        }

        string result(stk.size(), ' ');
        for (int i = stk.size() - 1; i >= 0; --i) {
            result[i] = stk.top();
            stk.pop();
        }
        return result;
}
};
