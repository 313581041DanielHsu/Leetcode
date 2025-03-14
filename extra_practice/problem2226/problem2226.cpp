class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l=1,r=*max_element(candies.begin(),candies.end());
        //cout<<r<<" "<<l;
        long long mid,temp;
        while(l<=r){
            mid=(r+l)/2;
            temp=0;
            for(int i=0;i<candies.size();i++){
                temp=temp+candies[i]/mid;
                if(temp>=k){
                    l=mid+1;
                    break;
                }    
            }
            if(temp>=k){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return r;
    }
};
