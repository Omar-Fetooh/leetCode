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

  static bool proceed(pair<int, int> A, pair<int, int>B) {
	  if (A.second < B.second) return true;
	  else if (A.second > B.second) return false;
	  else {
		  return A.first < B.first;
	  }
  }

 vector<vector<int>> verticalTraversal(TreeNode* root) {
	  vector<vector<int>> ans;
	  queue<pair<TreeNode*, pair<int,int>>>q;
	  map<int, vector<pair<int,int>>>mp;
	  if (root == NULL) return ans;
	  q.push({ root,{0,0 } });

	  while (!q.empty()) {
		  auto it = q.front();
		  q.pop();
		
		  TreeNode* node = it.first;
		  int level = it.second.first;
		  int pos = it.second.second;

		  mp[pos].push_back({node->val, level});

		  if (node->left) q.push({ node->left,{level + 1, pos - 1 } });
		  if (node->right) q.push({ node->right, {level + 1, pos + 1} });
	  }

	  for (auto it : mp) {
		  sort(it.second.begin(), it.second.end(),proceed);
		  vector<int> temp;
		  for (int i = 0;i < it.second.size();i++) {
			  temp.push_back(it.second[i].first);
		  }
		  ans.push_back(temp);
	  }
	  return ans;
  }
};