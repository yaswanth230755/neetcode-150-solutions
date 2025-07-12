// class DSU {
//     vector<int> Parent, Size;
// public:
//     DSU(int n) {
//         Parent.resize(n + 1);
//         Size.resize(n + 1);
//         for (int i = 0; i <= n; i++) {
//             Parent[i] = i;
//             Size[i] = 1;
//         }
//     }

//     int find(int node) {
//         if (node != Parent[node]) {
//             Parent[node] = find(Parent[node]);
//         }
//         return Parent[node];
//     }

//     bool unionBySize(int u, int v) {
//         int pu = find(u);
//         int pv = find(v);
//         if (pu == pv) return false;
//         if (Size[pu] >= Size[pv]) {
//             Size[pu] += Size[pv];
//             Parent[pv] = pu;
//         } else {
//             Size[pv] += Size[pu];
//             Parent[pu] = pv;
//         }
//         return true;
//     }
// };

// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int ROWS = grid.size();
//         int COLS = grid[0].size();
//         DSU dsu(ROWS * COLS);

//         int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//         int islands = 0;

//         auto index = [&](int r, int c) {
//             return r * COLS + c;
//         };

//         for (int r = 0; r < ROWS; r++) {
//             for (int c = 0; c < COLS; c++) {
//                 if (grid[r][c] == '1') {
//                     islands++;
//                     for (auto& d : directions) {
//                         int nr = r + d[0];
//                         int nc = c + d[1];
//                         if (nr >= 0 && nc >= 0 && nr < ROWS && 
//                             nc < COLS && grid[nr][nc] == '1') {
//                             if (dsu.unionBySize(index(r, c), index(nr, nc))) {
//                                 islands--;
//                             }
//                         }
//                     }
//                 }
//             }
//         }

//         return islands;
//     }
// };



class Solution {
    vector<pair<int,int>> coordinates={{-1,0},{1,0},{0,1},{0,-1}};
    void dfs(vector<vector<char>>& grid,int i,int j){
        // grid[i][j]='*';
        // if(i+1<grid.size() && grid[i+1][j]=='1'){
        //     dfs(grid,i+1,j);
        // }
        // if(j+1<grid[0].size() && grid[i][j+1]=='1'){
        //     dfs(grid,i,j+1);
        // }
        // if(i>0 && grid[i-1][j]=='1'){
        //     dfs(grid,i-1,j);
        // }
        // if(j>0 && grid[i][j-1]=='1'){
        //     dfs(grid,i,j-1);
        // }

        grid[i][j]='*';
        int du,dv;
        for(const auto& [x,y] : coordinates){
            du=i+x;
            dv=j+y;
            if(du>=0 && du<grid.size() && dv>=0 && dv<grid[0].size() && grid[du][dv]=='1'){
                dfs(grid,du,dv);
            }
        }
    }
    void bfs(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>& visited){
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=true;
        int u,v;
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(const auto [dx,dy] : coordinates){
                u=x+dx;
                v=y+dy;
                if(u>=0 && u<grid.size() && v<grid[0].size() && v>=0 && grid[u][v]=='1' && !visited[u][v]){
                    q.push({u,v});
                    visited[u][v]=true;
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int number=0,m=grid.size(),n=grid[0].size();

        // dfs
        // for(int i=0;i<grid.size();i++){
        //     for(int j=0;j<grid[0].size();j++){
        //         if(grid[i][j]=='1'){
        //             dfs(grid,i,j);
        //             number++;
        //         }
        //     }
        // }


        // bfs
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    bfs(grid,i,j,visited);
                    number++;
                }
            }
        }


        // we should not modify input
        // for(int i=0;i<grid.size();i++){
        //     for(int j=0;j<grid[0].size();j++){
        //         if(grid[i][j]=='*'){
        //             grid[i][j]='1';
        //         }
        //     }
        // }
        return number;
    }
};