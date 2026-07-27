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
    TreeNode* dfsLCA(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (node->val >= min(p->val, q->val) && node->val <= max(p->val, q->val))
            return node;
        if (node->val < p->val && node->val < q->val)
            return dfsLCA(node->right, p, q);
        else if (node->val > p->val && node->val > q->val)
            return dfsLCA(node->left, p, q);

        return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfsLCA(root, p, q);
    }
};