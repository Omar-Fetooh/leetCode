class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size());
        int balls = 0, moves = 0;

        for (int i = 0; i < boxes.size(); i++) {
            ans[i] += moves;
            balls += boxes[i] == '1';
            moves += balls;
        }
        moves = 0;
        balls = 0;
        for (int i = boxes.size() - 1; i >= 0; i--) {
            ans[i] += moves;
            balls += boxes[i] == '1';
            moves += balls;
        }

        return ans;
    }
};