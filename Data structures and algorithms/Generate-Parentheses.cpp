class Solution {
public:

void backtrack(vector<string>& vec, string& str, int n, int open, int close) {
    if (close == n) {
        vec.push_back(str);
        return;
    }
    if (open < n) {
        str.push_back('(');
        backtrack(vec, str,n, open + 1, close);
        str.pop_back();
    }
    if (open > close) {
        str.push_back(')');
        backtrack(vec, str, n, open, close + 1);
        str.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string str;
        backtrack(ans,str,n,0,0);
        return ans;
    }
};