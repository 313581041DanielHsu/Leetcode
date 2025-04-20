/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxSum = INT_MIN;  // 用來儲存全域的最大路徑和

    int maxGain(TreeNode* node) {
        if (!node) return 0;  // 空節點回傳 0

        // 左右子樹的最大「貢獻值」，小於0的就不加
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        // 以當前節點為「最高點」的路徑和（包含左右兩邊）
        int currentMaxPath = node->val + leftGain + rightGain;

        // 更新全域最大路徑和
        maxSum = max(maxSum, currentMaxPath);

        // 回傳此節點對父節點的最大「單邊貢獻值」
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);  // 開始遞迴
        return maxSum;
    }
};

