class Solution {
    int optimal(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<int> distance(n, INT_MAX);
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& v : flights)
            adj[v[0]].emplace_back(v[1], v[2]);

        queue<pair<int, int>> q;
        q.push({src, 0});
        distance[src] = 0;

        k++; // We can take at most k edges → k+1 nodes (levels)

        while (!q.empty() && k--) {
            int len = q.size();
            vector<int> temp = distance; // hold updates for this level only
            for (int i = 0; i < len; ++i) {
                auto [node, dis] = q.front();
                q.pop();
                if(distance[node]<dis)
                    continue;
                for (auto [v, wt] : adj[node]) {
                    if (dis + wt < temp[v]) {
                        temp[v] = dis + wt;
                        q.push({v, temp[v]});
                    }
                }
            }
            distance = temp;
        }

        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
    int bellmonFord(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> tmpPrices = prices;

            for (const auto& flight : flights) {
                int s = flight[0];
                int d = flight[1];
                int p = flight[2];

                if (prices[s] == INT_MAX)
                    continue;

                if (prices[s] + p < tmpPrices[d])
                    tmpPrices[d] = prices[s] + p;
            }

            prices = tmpPrices;
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        return optimal(n,flights,src,dst,k);
        return bellmonFord(n,flights,src,dst,k);
    }
};