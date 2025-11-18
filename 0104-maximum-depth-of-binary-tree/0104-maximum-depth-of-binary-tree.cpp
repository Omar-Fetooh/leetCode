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
    int cnt=0,maxi=0;
    int maxDepth(TreeNode* root) {
        if(root){
            ++cnt;
            maxi=max(maxi,cnt);
            maxDepth(root->left);
            if(root->left) cnt--;
            maxDepth(root->right);
            if(root->right) cnt--;
        }
        else{
            return 0;
        }
        return maxi;
    }
};