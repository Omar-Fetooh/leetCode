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
    void flatten(TreeNode* root) {
        TreeNode* prev = NULL;
        dfsFlatten(root, prev);
    }

    void dfsFlatten(TreeNode* node, TreeNode*& prev) {
        if (node == NULL)
            return;
        dfsFlatten(node->right, prev);
        dfsFlatten(node->left, prev);
        node->right = prev;
        node->left = nullptr;
        prev = node;
    }
};