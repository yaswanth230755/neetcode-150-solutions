class Solution {
    bool hasCycleDFS(vector<vector<int>>& adj,int node,vector<int>& state){
        state[node] = 1; // Visiting
        for (int neighbor : adj[node]) {
            if (state[neighbor] == 1) return true; // Back edge (cycle)
            if (state[neighbor] == 0 && hasCycleDFS(adj, neighbor, state))
                return true;
        }
        state[node] = 2; // Visited
        return false;
    }
    bool topoSortDFS(int numCourses,vector<vector<int>>& prerequisites){
        vector<vector<int>> adj(numCourses);
        vector<int> state(numCourses, 0); // 0 = unvisited, 1 = visiting, 2 = visited

        for (const auto& pair : prerequisites) {
            adj[pair[1]].push_back(pair[0]); // u → v
        }

        for (int i = 0; i < numCourses; ++i) {
            if (state[i] == 0 && hasCycleDFS(adj, i, state))
                return false;
        }

        return true;
    }
    bool topoSortKahn(int numCourses,vector<vector<int>>& prerequisites){
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph and compute in-degrees
        for (const auto& pair : prerequisites) {
            int u = pair[1], v = pair[0];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            count++;

            for (int neighbor : adj[node]) {
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If we visited all courses, return true
        return count == numCourses;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // use topological sort or cycle detection(bfs or dfs)
        return topoSortDFS(numCourses,prerequisites);
        //return topoSortKahn(numCourses,prerequisites);
    }
};
