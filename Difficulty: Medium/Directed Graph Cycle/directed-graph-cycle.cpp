class Solution {
  public:
  bool dfs(int node, vector<int>& visited, vector<int>& pathVisited, vector<vector<int>>& adj) {
			visited[node] = 1;
			pathVisited[node] = 1;
			for (auto it : adj[node]) {
				if (!visited[it]) {
					if (dfs(it, visited, pathVisited, adj)) return true;
				}
				else if (pathVisited[it]) return true;
			}
			pathVisited[node] = 0;
			return false;
		}

		bool isCyclic(int V, vector<vector<int>>& edges) {
			// code here
			vector<vector<int>>adj(V);
			for (int i = 0;i < edges.size();i++) {
				int u = edges[i][0];
				int v = edges[i][1];
				adj[u].push_back(v);
			}

			vector<int> visited(V);
			vector<int> pathVisited(V);

			for (int i = 0;i < V;i++) {
				if (!visited[i]) {
					if (dfs(i, visited, pathVisited, adj)) return true;
				}
			}
				return false;
		}

};