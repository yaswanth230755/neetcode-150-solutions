class DSU{
    public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
        int find(int i){
            // if(parent[i]!=i){
            //     parent[i]=find(parent[i]);
            // }
            // return parent[i];
            int root=i;
            while(root!=parent[root]){
                root=parent[root];
            }
            int next;
            while(i!=root){
                next=parent[i];
                parent[i]=root;
                i=next;
            }
            return root;
        }

        bool unionSet(int i,int j){
            i=find(i);
            j=find(j);
            if(i==j)
            return false;
            if(rank[i]<rank[j]){
                swap(i,j);
            }
            parent[j]=i;
            if(rank[i]==rank[j]){
                rank[i]++; // depth
            }
            // rank[i]+=rank[j]; // size
            return true;
        }
};
class Solution {
    // DFS Helper to detect cycles in an undirected graph
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int parent) {
        visited[node] = true;

        for (const int& neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (!dfs(neighbor, adj, visited, node))
                    return false;
            } else if (neighbor != parent) {
                // If visited and not the parent → cycle detected
                return false;
            }
        }
        return true;
    }

    // Wrapper to ensure all nodes are visited (connectivity check)
    bool DFS(int n, vector<vector<int>>& adj) {
        vector<bool> visited(n, false);

        // Start DFS from node 0 and check for cycles
        if (!dfs(0, adj, visited, -1))
            return false;

        // Check if all nodes were visited → graph is connected
        for (int i = 0; i < n; ++i) {
            if (!visited[i])
                return false;
        }

        return true;
    }

    // BFS (your version is already correct and optimal)
    bool bfs(int n, vector<vector<int>>& adj) {
        vector<bool> visited(n, false);
        queue<pair<int, int>> q;
        q.push({0, -1});
        visited[0] = true;
        int count = 1;

        while (!q.empty()) {
            auto [node, parent] = q.front(); 
            q.pop();

            for (const int& neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, node});
                    count++;
                } else if (neighbor != parent) {
                    return false; // cycle
                }
            }
        }

        return count == n;
    }
    bool disjointset(int n,vector<vector<int>>& edges){
        DSU dsu(n);
        for(const auto& v : edges){
            if(!dsu.unionSet(v[0],v[1])){
                return false;
            }
        }
        // int count=0;
        // for(int i=0;i<n;i++){
        //     if(parent[i]==i){
        //         count++;
        //     }
        // }
        // return count==1;
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // disjoint sets,bfs,dfs
        if (edges.size() != n - 1)
            return false;

        return disjointset(n,edges);

        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            if (edge[0] == edge[1])
                return false; // Self-loop
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        return bfs(n, adj);
        return DFS(n, adj);
    }
};
