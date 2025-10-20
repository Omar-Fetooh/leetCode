class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, h = matrix.size() - 1, mid, row=0;

        // to find each row
        while (l <= h) {
            mid = l + (h - l) / 2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] > target)
                h = mid - 1;
            else {
                row = mid;
                l = mid + 1;
            }
        }

        l = 0, h = matrix[l].size() - 1;

        while (l <= h) {
            mid = l + (h - l) / 2;
            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] > target)
                h = mid - 1;
            else {
                l = mid + 1;
            }
        }

        return false;
    }
};