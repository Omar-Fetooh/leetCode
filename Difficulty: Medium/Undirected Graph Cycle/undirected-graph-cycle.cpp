class Solution {
    private:
    bool detect(int src, vector<vector<int>>adj, vector<int>&visited) {
			queue<pair<int, int>>q;
			q.push({ src,-1 });
			visited[src] = 1;
			while (!q.empty())
			{
				int node = q.front().first;
				int parent = q.front().second;
				q.pop();
				for (auto neighbour : adj[node]) {
					if (!visited[neighbour]) {
						q.push({ neighbour,node });
						visited[neighbour] = 1;
					}
					else if (parent != neighbour) return true;
				}
			}
			return false;
	}
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
       vector<vector<int>>adj(V);
			for (auto& e : edges) {
			if (e.size() > 1) {

				int u = e[0];
 				int v = e[1];
				adj[u].push_back(v);
				adj[v].push_back(u);
				}
			}

			vector<int>visited(V);
			for (int i = 0;i < V;i++) {
				if (!visited[i]) {
					if(detect(i, adj, visited)) return true;
				}
			}
			return false;
        
    }
};