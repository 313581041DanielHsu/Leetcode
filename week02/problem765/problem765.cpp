class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int condition,temp,ans=0;
        for(int i=0;i<row.size()-1;i=i+2){
            if(row[i]%2==0){
                if(row[i+1]==row[i]+1){
                    continue;
                }else{
                    for(int j=i+1;j<row.size();j++){
                        if(row[j]==row[i]+1){
                            temp=row[i+1];
                            row[i+1]=row[j];
                            row[j]=temp;
                            break;
                        }
                    }
                    ans++;
                }
            }else{
                if(row[i+1]==row[i]-1){
                    continue;
                }else{
                    for(int j=i+1;j<row.size();j++){
                        if(row[j]==row[i]-1){
                            temp=row[i+1];
                            row[i+1]=row[j];
                            row[j]=temp;
                            break;
                        }
                    }
                    ans++;
                }
            }
            
        }
        return ans;
    }
};


/*
我的解法的核心是：
遍歷座位陣列，每次檢查 row[i] 是否和 row[i+1] 形成正確的情侶對。
如果不是正確的情侶對：
在剩餘的座位中尋找 row[i] 的正確伴侶，並交換位置。
計算交換次數，直到所有情侶都坐在一起。
這是一種 貪心演算法 (Greedy Algorithm)，透過 局部最優解（每次只進行一次交換）來達成全域最優解（最少交換次數）。
*/
