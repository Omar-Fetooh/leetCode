/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        vector<vector<Node*>> levels;
        q.push(root);

        while (!q.empty()) {
            vector<Node*> level;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                level.push_back(node);
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            level.push_back(nullptr);
            levels.push_back(level);
        }
        for (int i = 0; i < levels.size(); i++) {
            for (int j = 0; j < levels[i].size() - 1; j++) {
                levels[i][j]->next = levels[i][j + 1];
            }
        }
        return root;
    }
};