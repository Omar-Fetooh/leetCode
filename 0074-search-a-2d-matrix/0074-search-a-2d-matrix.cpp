class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), specialRow = -1;
        int l = 0, h = m - 1;

        while (l <= h) {
            int mid = (l + h) / 2;
            if (matrix[mid][0] <= target) {
                specialRow = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
     if (specialRow == -1) return false;
        l = 0;
        h = n - 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (matrix[specialRow][mid] == target) {
                return true;
            } else if (matrix[specialRow][mid] > target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
};