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
public:

    void preOrder(TreeNode* node, vector<int>& leftTree){
        if(node==NULL) {
            leftTree.push_back(-1000);
            return;
        }
        leftTree.push_back(node->val);
        preOrder(node->left,leftTree);
        preOrder(node->right,leftTree);
    }

    void revPreOrder(TreeNode* node, vector<int>& rightTree){
        if(node==NULL) {
            rightTree.push_back(-1000);
            return;
        }
        rightTree.push_back(node->val);
        revPreOrder(node->right,rightTree);
        revPreOrder(node->left,rightTree);
    }

    bool isSymmetric(TreeNode* root) {
        vector<int> leftTree;
        vector<int> rightTree;

        preOrder(root->left,leftTree);
        revPreOrder(root->right,rightTree);

        if(leftTree.size()!= rightTree.size()) return false;

        for(int i=0;i<leftTree.size();i++){
            if(leftTree[i]!=rightTree[i]) return false;
        }

        return true;
    }
};