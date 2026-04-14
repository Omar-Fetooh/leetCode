class Solution {
public:

			void setZeroes(vector<vector<int>>& matrix) {
				int m = matrix.size();
				int n = matrix[0].size();
				set<int> stOfZeroRows;
				set<int> stOfZeroCols;
				for (int i = 0;i < m;i++) {
					for (int j = 0;j < n;j++) {
						if (matrix[i][j] == 0) {
							stOfZeroRows.insert(i);
							stOfZeroCols.insert(j);
						}
					}
				}
				for (int i = 0;i < m;i++) {
					for (int j = 0;j < n;j++) {
						if (stOfZeroRows.count(i)|| stOfZeroCols.count(j)){
							matrix[i][j]=0;
						}
					}
				}
			}
};