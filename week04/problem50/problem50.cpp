class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;  // x^0 = 1
        long long power = n;     
        if (power < 0) {
            x = 1 / x;
            power = -power;
        }
        double half = myPow(x, power / 2);
        return (power % 2 == 0) ? half * half : half * half * x;
    }
};


/*
1.處理特殊情況
當 n == 0，直接回傳 1，因為任何數的 0 次方都是 1。

2.處理負數指數
如果 n 是負數：
轉換為 1/x
n 取絕對值來計算

3.快速冪法
使用 遞迴分治法 來加速計算 x^n：
x^n = (x^(n/2))^2 （如果 n 是偶數）
x^n = (x^(n/2))^2 * x （如果 n 是奇數）

這種方法能夠將每次運算的問題減半，從而 將時間複雜度從暴力解的 O(n) 降到 O(log n)。
*/
