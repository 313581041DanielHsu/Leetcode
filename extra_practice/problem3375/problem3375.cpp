class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(nums[0]<k){
            return -1;
        }
        int ans=0;
        for(int i=nums.size()-1;i>=1;i--){
            if(nums[i-1]==nums[i]){
                continue;
            }else{
                ans++;
            }
        }
        if(nums[0]!=k){
            ans++;
        }
        return ans;
    }
};
