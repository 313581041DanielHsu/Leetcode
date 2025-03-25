class Solution {
public:
    inline void heapify(vector<int>& nums, int l, int r){
        int parent=l, child=(parent<<1)+1;
        if (child>r) return;
        if (child+1 <= r  && nums[child]<nums[child+1]) child++;
        if (nums[parent]>nums[child]) return;
        swap(nums[parent], nums[child]);
        heapify(nums, child, r);
    }
    inline void heap_sort(vector<int>& nums){
        const int n=nums.size();
        for(int i=n/2-1; i>=0; i--)
            heapify(nums, i, n-1);
        for(int i=n-1; i>0; i--){
            swap(nums[0], nums[i]);
            heapify(nums, 0, i-1);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        heap_sort(nums);
        return nums;
    }
};
