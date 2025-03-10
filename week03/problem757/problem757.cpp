class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int ans=2;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int temp1=intervals[0][1]-1,temp2=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=temp1){
                //cout<<"Case1"<<endl;
                //cout<<"temp1 = "<<temp1<<",temp2 = "<<temp2<<endl;
                continue;
            }else if(intervals[i][0]<=temp2&&intervals[i][1]<=temp2){
                //cout<<"Case2"<<endl;
                temp1=intervals[i][1]-1;
                temp2=intervals[i][1];
                //cout<<"temp1 = "<<temp1<<",temp2 = "<<temp2<<endl;
                ans=ans+1;
            }else if(intervals[i][0]<=temp2){
                //cout<<"Case3"<<endl;
                temp1=temp2;
                temp2=intervals[i][1];
                ans=ans+1;
                //cout<<"temp1 = "<<temp1<<",temp2 = "<<temp2<<endl;
            }else{
                //cout<<"Case4"<<endl;
                temp1=intervals[i][1]-1;
                temp2=intervals[i][1];
                ans=ans+2;
                //cout<<"temp1 = "<<temp1<<",temp2 = "<<temp2<<endl;
            }
        }
        return ans;
    }
};



/*
步驟概述：
1.按照 end 進行排序：
這樣可以優先處理較早結束的區間，確保選擇的數字能覆蓋最多的後續區間。
2.初始化：
temp1 = intervals[0][1] - 1 (區間的倒數第二個數)
temp2 = intervals[0][1] (區間的最後一個數)
ans = 2 (因為我們至少要選 temp1 和 temp2 來覆蓋第一個區間)
3.遍歷 intervals，嘗試用 temp1 和 temp2 覆蓋新的區間：
Case 1 (intervals[i][0] <= temp1) → 當前區間已經被覆蓋，不做任何改變。
Case 2 (intervals[i][0] <= temp2 && intervals[i][1] <= temp2)
→ 當前區間的 end 也被覆蓋，但 start 沒有覆蓋，只需要選一個新數。
Case 3 (intervals[i][0] <= temp2)
→ 當前區間的 start 在 temp2 內，但 end 超出 temp2，需要選擇一個新數。
Case 4 (intervals[i][0] > temp2)
→ 這個區間完全沒有覆蓋，需要選擇兩個新數。
*/
