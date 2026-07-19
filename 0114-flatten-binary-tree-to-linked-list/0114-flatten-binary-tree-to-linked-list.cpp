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
    void preOrder(TreeNode* node, vector<TreeNode*>& v) {
        if (!node)
            return;
        v.push_back(node);
        preOrder(node->left, v);
        preOrder(node->right, v);
    }

    void flatten(TreeNode* root) {
        vector<TreeNode*> v;
        preOrder(root, v);
        v.push_back(NULL);
        for (int i = 0; i < v.size() - 1; i++) {
            v[i]->left = NULL;
            v[i]->right = v[i + 1];
        }
    }
};