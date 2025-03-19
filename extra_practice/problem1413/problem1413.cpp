class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int t=nums[0];
        for(int i=1;i<nums.size();i++){
            nums[i]=nums[i-1]+nums[i];
            if(nums[i]<t){
                t=nums[i];
            }
        }
        if(-1*t<0){
            return 1;
        }
        return -1*t+1;
    }
};
