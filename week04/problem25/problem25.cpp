class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;  

        ListNode* temp = head;
        int length = 0;
        while (temp) {
            length++;
            temp = temp->next;
        }

        ListNode* newhead = nullptr;
        ListNode* prev_tail = nullptr;
        ListNode* cur = head;

        while (length >= k) {
            ListNode* pre = nullptr;
            ListNode* start = cur;  
            ListNode* nex;

            for (int i = 0; i < k; i++) {
                nex = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nex;
            }

            if (!newhead) {
                newhead = pre;
            }

            if (prev_tail) {
                prev_tail->next = pre;
            }
            prev_tail = start; 

            length -= k;
        }

        prev_tail->next = cur;

        return newhead;
    }
};


/*
1.計算鏈表長度：
遍歷鏈表一次，計算總長度 length，確保有足夠的節點可供反轉。

2.迭代處理，每 k 個節點為一組反轉：
設置指標：
cur：當前節點，從 head 開始
pre：前一個節點，初始為 nullptr
nex：存儲 cur->next，避免丟失鏈表連接

反轉 k 個節點：
逐個調整指針，使 cur 指向 pre，反轉順序

更新 newhead：
第一組反轉後，將 newhead 設為 pre（新的頭節點）

連接前一組與當前組：
用 prev_tail 來連接前一組反轉後的尾巴和當前組的頭
prev_tail = start，更新 prev_tail 為反轉後的尾節點

3.處理剩餘不足 k 的部分：
直接連接 prev_tail->next = cur，保持原順序。
*/
