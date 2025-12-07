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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* temp= new TreeNode(val);
            return temp;
        }
        TreeNode* curr = root;
        while (true) {
            if (curr->val > val) {
                if (curr->left == NULL) {
                    TreeNode* temp = new TreeNode(val);
                    curr->left = temp;
                    return root;
                }
                curr = curr->left;
            } else if (curr->val < val) {
                if (curr->right==NULL) {
                    TreeNode* temp = new TreeNode(val);
                    curr->right = temp;
                    return root;
                }
                curr = curr->right;
            }
        }
    }
};