class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<int> prices(n, 1e9);
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++) {
            int from = flights[i][0];
            int to = flights[i][1];
            int price = flights[i][2];
            adj[from].push_back({to, price});
        }

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        pq.push({0, {src, 0}});
        prices[src] = 0;

        while (!pq.empty()) {
            int stops = pq.top().first;
            int node = pq.top().second.first;
            int cost = pq.top().second.second;

            pq.pop();
            if (stops > k)
                continue;

            for (auto it : adj[node]) {
                int NeDest = it.first;
                int NePrice = it.second;

                if (cost + NePrice < prices[NeDest] && stops <= k) {
                    prices[NeDest] = cost + NePrice;
                    pq.push({stops + 1, {NeDest, cost + NePrice}});
                }
            }
        }
        if (prices[dst] == 1e9)
            return -1;
        else
            return prices[dst];
    }
};