class Solution {
public:
		void dfs(int row, int col, vector<vector<int>>&visited, vector<vector<char>>&board,vector<int>&drow,vector<int>&dcol) {
			visited[row][col] = 1;
			int m = board.size();
			int n = board[0].size();
			for (int i = 0;i < 4;i++) {
				int nrow = row + drow[i];
				int ncol = col + dcol[i];

				if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && board[nrow][ncol] == 'O' && visited[nrow][ncol] != 1) {
					dfs(nrow, ncol, visited, board, drow, dcol);
				}
			}
		}
		
		void solve(vector<vector<char>>& board) {
			int m = board.size();
			int n = board[0].size();
			vector<vector<int>>visited(m, vector<int>(n));
			vector<int>drow = { -1,0,1,0 };
			vector<int>dcol = { 0,1,0,-1 };
			for (int i = 0;i < n;i++) {
				if (board[0][i] == 'O') {
					dfs(0, i, visited, board, drow, dcol);
				}
				if (board[m-1][i] == 'O') {
					dfs(m-1, i, visited, board, drow, dcol);
				}
			}

			for (int i = 0;i < m;i++) {
				if (board[i][0] == 'O') {
					dfs(i, 0, visited, board, drow, dcol);
				}
				if (board[i][n-1] == 'O') {
					dfs(i, n-1, visited, board, drow, dcol);
				}
			}

			for (int i = 0; i < m; i++)
			{
				for (int j = 0;j < n;j++) {
					if (visited[i][j] == 0 && board[i][j]=='O') {
						board[i][j] = 'X';
					}
				}
			}

		}

};