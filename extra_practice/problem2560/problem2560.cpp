class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l=*min_element(nums.begin(),nums.end()),r=*max_element(nums.begin(),nums.end());
        //cout<<l<<" "<<r<<endl;
        int c,mid;
        while(l<r){
            c=0;
            mid=(l+r)/2;
            for(int i=0;i<nums.size();i++){
                if(nums[i]<=mid){
                    c++;
                    i++;
                }
            }
            if(c>=k){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};
