class Solution {
  public:
			int spanningTree(int V, vector<vector<int>>& edges) {
				// code here
				vector<vector<pair<int, int>>> adj(V);
				for (int i = 0;i < edges.size();i++) {
					int u = edges[i][0];
					int v = edges[i][1];
					int wt = edges[i][2];
					adj[u].push_back({v,wt});
					adj[v].push_back({u,wt});
				}
				priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
				pq.push({ 0,0 });
				vector<int> visited(V);
				int sum = 0;
				while (!pq.empty())
				{
					int wt = pq.top().first;
					int node = pq.top().second;
					pq.pop();
					if (visited[node]) continue;
					sum += wt;
					visited[node] = 1;
					for (auto it : adj[node]) {
						if (!visited[it.first]);
						pq.push({ it.second,it.first });
					}
				}
				return sum;
			}
};