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

*/
