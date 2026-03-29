class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto time : times) {
            int u = time[0], v = time[1], w = time[2];
            adj[u].push_back({v, w});
        }
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, k});

        while (!pq.empty()) {
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();
            for (auto& it : adj[node]) {
                int nbr = it.first;
                int wt = it.second;
                if (dist[nbr] > wt + time) {
                    dist[nbr] = wt + time;
                    pq.push({dist[nbr], nbr});
                }
            }
        }

        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};