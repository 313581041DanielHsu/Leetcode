class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans=0,left=0,right=people.size()-1;
        sort(people.begin(),people.end());
        while(left<=right){
            if(people[left]+people[right]<=limit){
                left++;
            }
            right--;
            ans++;
        }
        return ans;
    }
};

/*
1.排序 (Sorting)
先將 people 從小到大排序，方便搭配輕重的組合。

2.雙指針 (Two Pointers)
設 left = 0 指向最輕的人。
設 right = people.size() - 1 指向最重的人。
嘗試讓最輕和最重的人搭同一艘船：
如果 people[left] + people[right] ≤ limit，兩人一起搭船，left++、right--。
否則，people[right] 太重，只能自己搭船，right--。

3.計算船數
每次載運一組人就 boats++。
當 left > right 時，所有人都已經運送完成。
*/
