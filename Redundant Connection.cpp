class DSU{
    public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int find(int i){ // Full Path Compression
        if(parent[i]!=i){
            parent[i]=find(parent[i]);
        }
        return parent[i];
        // iterative version
    //     int root = i;

    // // Step 1: Find the root
    // while (parent[root] != root) {
    //     root = parent[root];
    // }

    // // Step 2: Path compression - make all nodes on the path point to the root
    // while (i != root) {
    //     int next = parent[i];
    //     parent[i] = root;
    //     i = next;
    // }

    // return root;
    }

    // int find(int i){ // Path Compression by Halving
    //     while(parent[i]!=i){
    //         i=parent[i];
    //     }
    //     return parent[i];
    // }

    bool unionSet(int i,int j){
        // union by rank
        i=find(i);
        j=find(j);
        if(i==j){
            return false;
        }
        if(rank[i]<rank[j]){
            swap(i,j);
        }
        parent[j]=i;
        rank[i]++;
        return true;
    // union by size
    //     int pu = find(u);
    // int pv = find(v);
    // if (pu == pv) return false;

    // if (rank[pv] > rank[pu]) {
    //     swap(pu, pv);
    // }

    // parent[pv] = pu;
    // rank[pu] += rank[pv]; // Add sizes together
    // return true;
    }
};
class Solution {
    // vector<bool> visit;
    // vector<vector<int>> adj;
    // unordered_set<int> cycle;
    // int cycleStart;
    // bool dfs(int node, int par) {
    //     if (visit[node]) {
    //         cycleStart = node;
    //         return true;
    //     }
    //     visit[node] = true;
    //     for (int nei : adj[node]) {
    //         if (nei == par) continue;
    //         if (dfs(nei, node)) {
    //             if (cycleStart != -1) cycle.insert(node);
    //             if (node == cycleStart) {
    //                 cycleStart = -1;
    //             }
    //             return true;
    //         }
    //     }
    //     return false;
    // }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // disjoint sets,dfs,bfs

        // int n = edges.size();
        // adj.resize(n + 1);
        // for (auto& edge : edges) {
        //     int u = edge[0], v = edge[1];
        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        // }

        // visit.resize(n + 1, false);
        // cycleStart = -1;
        // dfs(1, -1);

        // for (int i = edges.size() - 1; i >= 0; i--) {
        //     int u = edges[i][0], v = edges[i][1];
        //     if (cycle.count(u) && cycle.count(v)) {
        //         return {u, v};
        //     }
        // }
        // return {};



        // int n = edges.size();
        // vector<int> indegree(n + 1, 0);
        // vector<vector<int>> adj(n + 1);
        // for (auto& edge : edges) {
        //     int u = edge[0], v = edge[1];
        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        //     indegree[u]++;
        //     indegree[v]++;
        // }

        // queue<int> q;
        // for (int i = 1; i <= n; i++) {
        //     if (indegree[i] == 1) q.push(i);
        // }

        // while (!q.empty()) {
        //     int node = q.front(); q.pop();
        //     indegree[node]--;
        //     for (int nei : adj[node]) {
        //         indegree[nei]--;
        //         if (indegree[nei] == 1) q.push(nei);
        //     }
        // }

        // for (int i = edges.size() - 1; i >= 0; i--) {
        //     int u = edges[i][0], v = edges[i][1];
        //     if (indegree[u] == 2 && indegree[v]) 
        //         return {u, v};
        // }
        // return {};



        int n=edges.size();
        DSU dsu(n+1);
        for(const auto& v: edges){
            if(!dsu.unionSet(v[0],v[1])){
                return v;
            }
        }


    }
};
