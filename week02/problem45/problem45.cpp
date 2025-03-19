class Solution {
public:
    int jump(vector<int>& nums) {
        int times=0;
        if(nums.size()==1){
            return times;
        }
        for(int i=0;i<nums.size();i++){
            int best=0,bestpos=0;
            times++;
            for(int j=1;j<=nums[i]&&(i+j)<nums.size();j++){
                if(j+nums[i+j]>=best){
                    best=j+nums[i+j];
                    bestpos=i+j;
                }
                if((i+j)==nums.size()-1){
                    return times;
                }
            }
            cout<<"i= "<<i<<endl;
            cout<<"best= "<<best<<endl;
            cout<<"bestpos= "<<bestpos<<endl;
            cout<<"times= "<<times<<endl;
            i=bestpos-1;
            if(bestpos>=nums.size()-1){
                break;
            }
        }
        return times;
    }
};


/*
方法本質上是 貪心演算法 (Greedy Algorithm)，透過「選擇當前範圍內最遠能跳到的位置」，來確保達成最少跳躍次數。
*/
