/* Node Structure
class Node {
	public:
	int data;
	Node* left, *right;
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
}; */

class Solution {
	public:
	
	bool isLeaf(Node* root) {
		return root->left == NULL && root->right == NULL;
	}
	
	void addLeftBoundary(Node* root, vector<int>& res) {
		Node* cur = root->left;
		while (cur) {
			if (!isLeaf(cur))
				res.push_back(cur->data);
			if (cur->left)
				cur = cur->left;
			else
				cur = cur->right;
		}
	}
	void addRightBoundary(Node* root, vector<int>& res) {
		vector<int> temp;
		Node* cur = root->right;
		while (cur) {
			if (!isLeaf(cur))
				temp.push_back(cur->data);
			if (cur->right)
				cur = cur->right;
			else
				cur = cur->left;
		}
		
		for(int i =temp.size()-1;i>=0;i--){
		    res.push_back(temp[i]);
		}
		
	}
	
	void addLeafs(Node* root, vector<int>& res) {
	    Node* cur = root;
	    if(isLeaf(cur)) res.push_back(cur->data);
	    if(cur->left) addLeafs(cur->left, res);
	    if(cur->right) addLeafs(cur->right, res);
	}
	
	vector<int> boundaryTraversal(Node *root) {
		// code here
		vector<int> ans;
		if(!root) return ans;
		if(!isLeaf(root)) ans.push_back(root->data);
	    addLeftBoundary(root,ans);	
	    addLeafs(root, ans);
	    addRightBoundary(root, ans);
	    return ans;
	}
};
