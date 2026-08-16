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
    int kthInOrder(TreeNode* node, int& cnt, int k) {
        if (!node)
            return -1;

        int result = kthInOrder(node->left, cnt, k);

        if (result != -1) {
            return result;
        }

        cnt++;
        if (cnt == k)
            return node->val;

        return kthInOrder(node->right, cnt, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return kthInOrder(root, cnt, k);
    }
};