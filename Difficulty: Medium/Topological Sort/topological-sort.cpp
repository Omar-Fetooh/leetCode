class Solution {
  public:
   		void dfsTopo(int node, vector<int>&visited, stack<int>&st, vector<vector<int>>& adj) {
			visited[node] = 1;
			for (auto it : adj[node]) {
				if (!visited[it]) {
					dfsTopo(it, visited, st, adj);
				}
			}
			st.push(node);
		}

		vector<int> topoSort(int V, vector<vector<int>>& edges) {
			vector<vector<int>>adj(V);
			for (int i = 0;i < edges.size();i++) {
				int u = edges[i][0];
				int v = edges[i][1];
				adj[u].push_back(v);
			}
			vector<int>ans;
			vector<int>visited(V);
			stack<int>st;
			for (int i = 0;i < V;i++) {
				if (!visited[i]) {
					dfsTopo(i, visited, st, adj);
				}
			}

			while (!st.empty())
			{
				ans.push_back(st.top());
				st.pop();
			}
			return ans;

		}

};