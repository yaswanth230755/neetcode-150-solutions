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
    // int prims(vector<vector<int>>& points){
    //     int n=points.size();
    //     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    //     vector<vector<int>> adj(n,vector<int>(n,0));
    //     int weight,count=0,sum=0;
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             weight=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
    //             adj[i][j]=weight;
    //             adj[j][i]=weight;
    //         }
    //     }
    //     pq.push({0,0});
    //     vector<bool> visited(n,false); 
    //     vector<int> distance(n,INT_MAX);
    //     while(!pq.empty()){
    //         const auto [wt,index]=pq.top();
    //         pq.pop();
    //         if(count==n){
    //             break;
    //         }
    //         if(visited[index]){
    //             continue;
    //         }
    //         count++;
    //         sum+=wt;
    //         visited[index]=true;
    //         distance[index]=wt;
    //         for(int i=0;i<n;i++){
    //             if(!visited[i] && distance[i]>adj[index][i]){
    //                 pq.push({adj[index][i],i});
    //             }
    //         }
    //     }
    //     return (count==n)?sum:-1;
    // }
    int kruskal(vector<vector<int>>& points){
        int n=points.size();
        vector<pair<int,pair<int,int>>> vp;
        int weight;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                vp.push_back({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),{i,j}});
            }
        }
        DSU dsu= DSU(n);
        sort(vp.begin(),vp.end());
        int count=0,sum=0;
        for(const auto& p : vp){
            if(dsu.unionSet(p.second.first,p.second.second)){
                count++;
                sum+=p.first;
                if(count==n-1){
                    break;
                }
            }
        }
        return (count==n-1)?sum:-1;
    }
    int primsoptimal(vector<vector<int>>& points){
        int n = points.size(), node = 0;
        vector<int> dist(n, 100000000);
        vector<bool> visit(n, false);
        int edges = 0, res = 0;

        while (edges < n - 1) {
            visit[node] = true;
            int nextNode = -1;
            for (int i = 0; i < n; i++) {
                if (visit[i]) continue;
                int curDist = abs(points[i][0] - points[node][0]) + 
                               abs(points[i][1] - points[node][1]);
                dist[i] = min(dist[i], curDist);
                if (nextNode == -1 || dist[i] < dist[nextNode]) {
                    nextNode = i;
                }
            }
            res += dist[nextNode];
            node = nextNode;
            edges++;
        }
        return res;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // return prims(points);
        // return kruskal(points);
        return primsoptimal(points);
    }
};