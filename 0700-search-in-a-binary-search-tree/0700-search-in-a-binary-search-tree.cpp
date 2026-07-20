/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* node, int& val) {
        if (!node)
            return nullptr;

        else if (val < node->val) {
            return dfs(node->left, val);
        } else if (val > node->val) {
            return dfs(node->right, val);
        }

        return node;
    }

    TreeNode* searchBST(TreeNode* root, int val) { return dfs(root, val); }
};