class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==0){
                nums[i]=1;
                ans++;
                if(nums[i+1]==0){
                    nums[i+1]=1;
                }else{
                    nums[i+1]=0;
                }
                if(nums[i+2]==0){
                    nums[i+2]=1;
                }else{
                    nums[i+2]=0;
                }
            }
            if(i==nums.size()-3){
                if(nums[i+1]==1&&nums[i+2]==1){
                    return ans;
                }
            }
        }
        return -1;
    }
};
