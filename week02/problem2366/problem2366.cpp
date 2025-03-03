class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]<nums[i-1]){
                double t1=nums[i-1];
                double t2=nums[i];
                ans=ans+ceil(t1/t2)-1;
                nums[i-1]=nums[i-1]/ceil(t1/t2);
            }
        }        
        return ans;
    }
};


/*
從右往左遍歷陣列
因為我們要確保陣列是從左到右非遞減 (nums[i] ≥ nums[i-1])，所以從右開始處理，確保每一個 nums[i-1] 都滿足這個條件。
當 nums[i-1] > nums[i]，我們需要拆分 nums[i-1]

如果 nums[i-1] ≤ nums[i]，那麼這個數值已經符合條件，不需要做任何修改。
但如果 nums[i-1] > nums[i]，則必須拆分 nums[i-1]，讓拆分後的最大值不超過 nums[i]。
計算拆分的份數

要讓nums[i-1] 被拆分成 parts 個部分，每個部分的最大值都不超過 nums[i]。
ceil(nums[i-1] / nums[i]) 計算出需要拆分的最小份數 (parts)，確保每個部分的最大值不超過 nums[i]。
/*
