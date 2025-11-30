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
    bool flag = false;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val == q->val) {
            return isSameTree(p->left, q->left) &&
                   isSameTree(p->right, q->right);
        } else
            return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        dfs(root,subRoot);
        return flag;
    }
    TreeNode* dfs(TreeNode* root, TreeNode* subRoot) {
        if (!root)
            return NULL;
        if (isSameTree(root, subRoot)) {
            flag = true;
        }
        dfs(root->left, subRoot);
        dfs(root->right, subRoot);
        return NULL;
    }
};