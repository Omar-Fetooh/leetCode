class Solution {
    private:
    bool dfs(int node,int parent, vector<vector<int>>&adj, vector<int>& visited) {
    			
    			visited[node] = 1;
    			
    			for (auto neighbour : adj[node]) {
    				if (!visited[neighbour]) {
    					if (dfs(neighbour, node, adj, visited)) return true;
    				}
    				else if (parent != neighbour) return true;
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
					if(dfs(i, -1,adj, visited)) return true;
				}
			}
			return false;
        
    }
};