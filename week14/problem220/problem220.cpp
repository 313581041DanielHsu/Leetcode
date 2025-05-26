class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long> window; // 用來維持大小為 indexDiff 的滑動窗口

        for (int i = 0; i < nums.size(); i++) {
            auto it = window.lower_bound((long)nums[i] - valueDiff);
            if (it != window.end() && *it <= (long)nums[i] + valueDiff) {
                return true;
            }

            window.insert(nums[i]);
            if (window.size() > indexDiff) {
                window.erase(nums[i - indexDiff]);
            }
        }
        return false;
    }
};
