class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, path, result);
        return result;
    }

    void backtrack(vector<int>& nums, vector<bool>& used, 
                   vector<int>& path, vector<vector<int>>& result) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;

            // 做選擇
            path.push_back(nums[i]);
            used[i] = true;

            // 繼續遞迴
            backtrack(nums, used, path, result);

            // 回溯：撤銷選擇
            path.pop_back();
            used[i] = false;
        }
    }
};

