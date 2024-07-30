class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int, int>>vop;
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (matrix[i][j] == 0) {
                    vop.push_back({ i,j });
                }
            }
        }
        for (int i = 0;i < vop.size();i++) {
        int fixI=vop[i].first, fixJ=vop[i].second;
        int j = 0;
            while (j < n) {
                matrix[fixI][j++] = 0;
            }
            j = 0;
            fixI = vop[i].first, fixJ = vop[i].second;
            while (j < m) {
                matrix[j++][fixJ] = 0;
            }
        }
    }
};