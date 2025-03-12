class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0]; 
        });
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=intervals[i-1][1]){
                if(intervals[i-1][1]>intervals[i][1]){
                    intervals[i][1]=intervals[i-1][1];
                    intervals[i][0]=intervals[i-1][0];
                    intervals[i-1][0]=-1;
                    intervals[i-1][1]=-1;
                }else{
                    intervals[i][0]=intervals[i-1][0];
                    intervals[i-1][0]=-1;
                    intervals[i-1][1]=-1;
                }
            }
        }
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]!=-1&&intervals[i][1]!=-1){
                ans.push_back(intervals[i]);
            }
        }
        return ans;        
    }
};
