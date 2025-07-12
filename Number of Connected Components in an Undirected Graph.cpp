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
    void dfs(int i,vector<vector<int>>& adj,vector<bool>& visited){
        visited[i]=true;
        for(const auto& neigbhour : adj[i]){
            if(!visited[neigbhour]){
                dfs(neigbhour,adj,visited);
            }
        }
    }
    int DFS(int n,vector<vector<int>>& adj){
        vector<bool> visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited);
                count++;
            }
        }
        return count;
    }
    int bfs(int n,vector<vector<int>>& adj){
        queue<int> q;
        vector<bool> visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
                int node;
                while(!q.empty()){
                    node=q.front();
                    q.pop();
                   for(const auto& neigbhour : adj[node]){
                        if(!visited[neigbhour]){
                            q.push(neigbhour);
                            visited[neigbhour]=true;
                        }
                    }
                }
                count++;
            }
        }
        return count;
    }

    int dsu(int n,vector<vector<int>>& edges){
        DSU dsu = DSU(n);
        for(const auto& edge : edges){
            dsu.unionSet(edge[0],edge[1]);
        }
        int no_of_comp=0;
        for(int i=0;i<n;i++){
            if(dsu.parent[i]==i){
                //cout<<i<<endl;
                no_of_comp++;
            }
        }
        return no_of_comp;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // disjoint set,dfs,bfs

        return dsu(n,edges);
        vector<vector<int>> adj(n);
        for(const auto& v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        return DFS(n,adj);
        return bfs(n,adj);
    }
};
