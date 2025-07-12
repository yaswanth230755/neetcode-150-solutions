class Solution {
    bool printpath(int k, int n, vector<vector<int>>& predecessor) {
        if (k == n) {
            cout << k;
            return true;
        }
        if (predecessor[k][n] == -1) {
            cout << "Path does not exist from " << k << " to " << n << "\n";
            return false;
        }
        if (printpath(k, predecessor[k][n], predecessor)) {
            cout << " -> " << n;
            return true;
        }
        return false;
    }
    int dijkstra_pq(vector<vector<int>>& times, int n, int k){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int> distance(n + 1, INT_MAX);
        vector<int> parent(n + 1, -2); // Optional
        vector<bool> visited(n + 1, false);
        vector<vector<pair<int,int>>> adj(n + 1);
        for (const auto& v : times) {
            adj[v[0]].push_back({v[1], v[2]});
        }
        distance[k] = 0;
        pq.push({0, k});
        parent[k] = -1;
        int count = 0;
        int maxTime = 0;
        while (!pq.empty()) {
            const auto [dis, node] = pq.top();
            pq.pop();
            if(count==n){
                break;
            }
            if (visited[node]) continue;
            // or
            // if(mintime>=min[node]){
            //     continue;
            // }
            visited[node] = true;
            count++;
            maxTime = dis;
            for (const auto& [v, wt] : adj[node]) {
                if (!visited[v] && distance[v] > distance[node] + wt) {
                    distance[v] = distance[node] + wt;
                    parent[v] = node;
                    pq.push({distance[v], v});
                }
            }
        }
        // can do count by iterating the distance
        return (count == n) ? maxTime : -1;
    }
    int floydWarshall(vector<vector<int>>& times, int n, int k){
        vector<vector<int>> adj(n + 1, vector<int>(n + 1, INT_MAX));
        vector<vector<int>> predecessor(n + 1, vector<int>(n + 1, -1));
        // Initialization
        for (int i = 1; i <= n; ++i) {
            adj[i][i] = 0;
            predecessor[i][i] = i;
        }
        for (const auto& v : times) {
            adj[v[0]][v[1]] = v[2];
            predecessor[v[0]][v[1]] = v[0];
        }
        // Floyd-Warshall
        for (int l = 1; l <= n; ++l) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (adj[i][l] != INT_MAX && adj[l][j] != INT_MAX &&
                        adj[i][j] > adj[i][l] + adj[l][j]) {
                        adj[i][j] = adj[i][l] + adj[l][j];
                        predecessor[i][j] = predecessor[l][j];
                    }
                }
            }
        }
        // Print paths from k to all other nodes
        int maxDelay = 0;
        for (int i = 1; i <= n; ++i) {
            if (adj[k][i] == INT_MAX) return -1;
            maxDelay = max(maxDelay, adj[k][i]);
            // cout << "Shortest path from " << k << " to " << i << ": ";
            // printpath(k, i, predecessor);
            // cout << " | Time: " << adj[k][i] << "\n";
        }
        return maxDelay;
    }
    
    int dijkstra_q(vector<vector<int>>& times, int n, int k){
        vector<int> dist(n, INT_MAX);
        dist[k - 1] = 0;

        for (int i = 0; i < n - 1; ++i) {
            for (const auto& time : times) {
                int u = time[0] - 1, v = time[1] - 1, w = time[2];
                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        int maxDist = *max_element(dist.begin(), dist.end());
        return maxDist == INT_MAX ? -1 : maxDist;
    }

    int bellmonFord(vector<vector<int>>& times, int n, int k){
        vector<int> distance(n+1,INT_MAX);
        distance[k]=0;
        for(int i=1;i<=n-1;i++){
            for(const auto& time : times){
                if(distance[time[0]]!=INT_MAX){
                    distance[time[1]]=min(distance[time[1]],distance[time[0]]+time[2]);
                }
            }
        }
        int max=*max_element(distance.begin()+1,distance.end());
        return (max!=INT_MAX)?max:-1;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // dijkstra(can also do with queue no need of priority queue)
        // bellman
        // floyd warshall
        // dfs
        return dijkstra_pq(times,n,k);
        // return floydWarshall(times,n,k);
        // return dijkstra_q(times,n,k);
        // return bellmonFord(times,n,k);
    }
};
