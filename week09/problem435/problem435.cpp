class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        // 依照結束時間排序
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 1; // 第一個區間一定選
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= end) {
                // 沒有重疊，更新 end
                end = intervals[i][1];
                ++count;
            }
        }

        // 刪掉的數量 = 總數量 - 不重疊的數量
        return intervals.size() - count;
    }
};

