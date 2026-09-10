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
    pair<int, int> dfs(TreeNode* root, int& ans) {
        if (root->left == NULL && root->right == NULL) {
            ans++;
            return { root->val,1};
        }
        pair<int, int> leftValues;
        pair<int, int> rightValues;
        if (root->left)
            leftValues = dfs(root->left, ans);
        if (root->right)
            rightValues = dfs(root->right, ans);

        int sumNodes = leftValues.first + rightValues.first + root->val;
        int numNodes = leftValues.second + rightValues.second +1;

        if (sumNodes / numNodes == root->val)
            ans++;

        return {sumNodes, numNodes};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};