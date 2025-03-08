class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int window_size = cardPoints.size() - k;
        int min_window = INT_MAX;
        int sum = 0;
        int total_pts = 0;
        int L = 0, R = 0;
        for (;R < window_size;R++) {
            total_pts += cardPoints[R];
            sum += cardPoints[R];
        }
        min_window = sum;
        for (;R < cardPoints.size();R++, L++) {
            total_pts += cardPoints[R];
            sum += cardPoints[R];
            sum -= cardPoints[L];
            min_window = min(min_window, sum);
        }
        return total_pts - min_window;
    }
};