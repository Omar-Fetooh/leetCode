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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> level;
            int qLen = q.size();
            for (int i = 0; i < qLen; i++) {
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp->val);
                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
            }
            res.push_back(level);
        }
        return res;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> levelOrderAns = levelOrder(root);
        vector<int> ans;
        for (int i = 0; i < levelOrderAns.size(); i++) {
            ans.push_back(levelOrderAns[i][levelOrderAns[i].size() - 1]);
        }
        return ans;
    }
};