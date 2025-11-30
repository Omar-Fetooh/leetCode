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
    vector<int> vp;
    vector<int> vq;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vp.clear();
        vq.clear();
        dfs(p);
        dfs2(q);
        if (vp.size() != vq.size())
            return false;
        for (int i = 0; i < vp.size(); i++) {
            if (vp[i] != vq[i])
                return false;
        }
        return true;
    }

    TreeNode* dfs(TreeNode* p) {
        if (!p) {
            vp.push_back(-100000);
            return NULL;
        }
        vp.push_back(p->val);
        dfs(p->left);
        dfs(p->right);
        return nullptr;
    }
    TreeNode* dfs2(TreeNode* p) {
        if (!p) {
            vq.push_back(-100000);
            return NULL;
        }
        vq.push_back(p->val);
        dfs2(p->left);
        dfs2(p->right);
        return nullptr;
    }
};