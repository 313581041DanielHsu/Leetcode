class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size(),1);
        int ans=0;
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]){
                candy[i]=candy[i-1]+1;
                //cout<<"candy["<<i<<"]="<<candy[i]<<endl;
            }
        }
        //cout<<"-----"<<endl;
        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]&&candy[i]<=candy[i+1]){
                candy[i]=candy[i+1]+1;
               //cout<<"candy["<<i<<"]="<<candy[i]<<endl;
            }
        }
        for(int i=0;i<ratings.size();i++){
            ans=ans+candy[i];
        }
        return ans;
    }
};

/*
使用 兩輪遍歷 來確保糖果分配符合題目要求：
先從左到右遍歷 (確保遞增的關係)
再從右到左遍歷 (確保遞減的關係)
最後累加糖果數量
*/
