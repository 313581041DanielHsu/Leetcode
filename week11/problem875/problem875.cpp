class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=*max_element(piles.begin(),piles.end());
        long long mid,temp;
        while(l<=r){
            mid=(l+r)/2;
            temp=0;
            for(int i=0;i<piles.size();i++){
                if(piles[i]%mid==0){
                    temp=temp+(piles[i]/mid);
                }else{
                    temp=temp+(piles[i]/mid)+1;
                }
            }
            if(temp>h){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return l;
    }
};
