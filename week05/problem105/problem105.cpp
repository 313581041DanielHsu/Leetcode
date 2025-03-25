/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<int, int> inorderMap;
    int preorderIndex = 0;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return build(preorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, int start, int end) {
        if (start > end) return nullptr;

        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inorderIndex = inorderMap[rootVal];

        root->left = build(preorder, start, inorderIndex - 1);
        root->right = build(preorder, inorderIndex + 1, end);

        return root;
    }
};
