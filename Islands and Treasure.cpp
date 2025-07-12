class Solution {
    vector<pair<int,int>> directions={{-1,0},{1,0},{0,1},{0,-1}};

    // vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};
    // int INF = 2147483647;
    // vector<vector<bool>> visit;
    // int ROWS, COLS;
    // int dfs(vector<vector<int>>& grid, int r, int c) {
    //     if (r < 0 || c < 0 || r >= ROWS || 
    //         c >= COLS || grid[r][c] == -1 || visit[r][c]) {
    //         return INF;
    //     }
    //     if (grid[r][c] == 0) {
    //         return 0;
    //     }
    //     visit[r][c] = true;
    //     int res = INF;
    //     for (auto& dir : directions) {
    //         int cur = dfs(grid, r + dir[0], c + dir[1]);
    //         if (cur != INF) {
    //             res = min(res, 1 + cur);
    //         }
    //     }
    //     visit[r][c] = false;
    //     return res;
    // }
    // int bfs(vector<vector<int>>& grid, int r, int c) {
    //     queue<pair<int, int>> q;
    //     q.push({r, c});
    //     vector<vector<bool>> visit(ROWS, vector<bool>(COLS, false));
    //     visit[r][c] = true;
    //     int steps = 0;

    //     while (!q.empty()) {
    //         int size = q.size();
    //         for (int i = 0; i < size; i++) {
    //             auto [row, col] = q.front();
    //             q.pop();
    //             if (grid[row][col] == 0) return steps;
    //             for (auto& dir : directions) {
    //                 int nr = row + dir[0], nc = col + dir[1];
    //                 if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && 
    //                     !visit[nr][nc] && grid[nr][nc] != -1) {
    //                     visit[nr][nc] = true;
    //                     q.push({nr, nc});
    //                 }
    //             }
    //         }
    //         steps++;
    //     }
    //     return INF;
    // }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // dfs
        // ROWS = grid.size();
        // COLS = grid[0].size();
        // visit.assign(ROWS, vector<bool>(COLS, false));
        // for (int r = 0; r < ROWS; ++r) {
        //     for (int c = 0; c < COLS; ++c) {
        //         if (grid[r][c] == INF) {
        //             grid[r][c] = dfs(grid, r, c);
        //         }
        //     }
        // }


        // bfs
        // int m = grid.size();
        // int n = grid[0].size();
        // queue<pair<int, int>> q;
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (grid[i][j] == 0) {
        //             q.push({i, j});
        //         }
        //     }
        // }
        // vector<vector<int>> dirs = {{-1, 0}, {1, 0}, 
        //                             {0, -1}, {0, 1}};
        // while (!q.empty()) {
        //     int row = q.front().first;
        //     int col = q.front().second;
        //     q.pop();
            
        //     for (int i = 0; i < 4; i++) {
        //         int r = row + dirs[i][0];
        //         int c = col + dirs[i][1];
                
        //         if (r < 0 || r >= m || c < 0 || 
        //             c >= n || grid[r][c] != INT_MAX) {
        //             continue;
        //         }
                
        //         grid[r][c] = grid[row][col] + 1;
        //         q.push({r, c});
        //     }
        // }


        // Multi Source BFS
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!grid[i][j]){
                    q.push({i,j});
                }
            }
        }
        int u,v,distance=1,len;
        while(!q.empty()){
            len=q.size();
            while(len--){
                const auto [x,y]=q.front();
                q.pop();
                for(const auto& [dx,dy] : directions){
                    u=x+dx;
                    v=y+dy;
                    if(u>=0 && u<m && v>=0 && v<n && grid[u][v]==INT_MAX){
                        q.push({u,v});
                        grid[u][v]=distance;
                    }
                }
            }
            distance++;
        }
    }
};
