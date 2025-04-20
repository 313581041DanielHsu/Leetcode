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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: 遇到空節點或遇到目標節點，直接回傳
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        // 遞迴探索左右子樹
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // 若左右子樹都找到節點，代表此 root 是最近共同祖先
        if (left != nullptr && right != nullptr) {
            return root;
        }

        // 否則傳回有非空的那個子樹（若都為空會傳 null）
        return left != nullptr ? left : right;
    }
};
