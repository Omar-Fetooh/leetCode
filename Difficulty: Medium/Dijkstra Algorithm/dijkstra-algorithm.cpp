class Solution {
  public:

		vector<int> dijkstra(int V, vector<vector<int>>& edges, int src) {
			// Code here
			vector<vector<pair<int, int>>> adj(V);
			for (int i = 0;i < edges.size();i++) {
				int u = edges[i][0];
				int v = edges[i][1];
				int w = edges[i][2];
				adj[u].push_back({ v,w });
				adj[v].push_back({ u,w });
			}
			priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
			vector<int>dist(V, 1e9);
			dist[src] = 0;
			pq.push({ 0,src });
			while (!pq.empty()) {
				int lastDist = pq.top().first;
				int node = pq.top().second;
				pq.pop();

                if (lastDist > dist[node]) continue;


				for (auto it : adj[node]) {
					int w = it.second;
					int adjNode = it.first;

					if (lastDist + w < dist[adjNode]) {
						dist[adjNode] = lastDist + w;
						pq.push({ lastDist + w,adjNode });
					}
				}
			}
			return dist;
		}

};