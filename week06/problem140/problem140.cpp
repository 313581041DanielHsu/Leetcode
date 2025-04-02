class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> result;
        vector<string> path;
        backtrack(s, 0, dict, path, result);
        return result;
    }

    void backtrack(const string& s, int start, unordered_set<string>& dict,
                   vector<string>& path, vector<string>& result) {
        if (start == s.length()) {
            string sentence = "";
            for (int i = 0; i < path.size(); ++i) {
                sentence += path[i];
                if (i != path.size() - 1) sentence += " ";
            }
            result.push_back(sentence);
            return;
        }

        for (int end = start + 1; end <= s.length(); ++end) {
            string word = s.substr(start, end - start);
            if (dict.count(word)) {
                path.push_back(word);
                backtrack(s, end, dict, path, result);
                path.pop_back(); 
            }
        }
    }
};

