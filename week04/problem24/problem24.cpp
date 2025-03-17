class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;  
        }

        ListNode* newHead = head->next;  
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        ListNode* prev = nullptr; 

        while (temp1 && temp2) {
            temp1->next = temp2->next;
            temp2->next = temp1;

            if (prev) {
                prev->next = temp2;
            }
            prev = temp1;

            temp1 = temp1->next;  
            temp2 = (temp1 && temp1->next) ? temp1->next : nullptr;
        }

        return newHead;
    }
};


/*
1.初始條件：
如果鏈表長度為 0 或 1，直接返回 head。

2.交換相鄰節點：
讓 temp1 指向當前節點，temp2 指向下一節點。
交換 temp1 和 temp2，並更新指針連接。
使用 prev 保存前一組交換後的節點，避免鏈表中斷。

3.指標移動：
更新 temp1 和 temp2 以處理下一組相鄰節點。
*/
