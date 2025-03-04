class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n>0){
            if(n%3==2){
                return 0;
            }else{
                n=n/3;
            }
        }
        return true;
    }
};

/*
核心想法
如果 n 可以用 3^x 的和來表示，代表 n 的「三進制（Base 3）」只有 0 和 1，不能有 2。
這是因為 3^x 不能重複使用，因此「3 進制」的位數 不能有 2，否則我們無法用不同的 3^x 來組成 n。
解法步驟
不斷對 n 取 mod 3：
如果 n % 3 == 2，代表 n 不能用 3^x 來組成，直接回傳 false。
如果 n % 3 == 1 或 n % 3 == 0，則繼續處理 n //= 3。
重複這個過程直到 n == 0，如果一直沒有遇到 2，代表可以表示，回傳 true。  
*/
