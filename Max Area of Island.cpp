class Solution {
    vector<pair<int,int>> coordinates={{-1,0},{1,0},{0,1},{0,-1}};
    int dfs(vector<vector<int>>& grid,int i,int j){
        int curr=1;
        grid[i][j]=2;
        int du,dv;
        for(const auto& [x,y] : coordinates){
            du=i+x;
            dv=j+y;
            if(du>=0 && du<grid.size() && dv>=0 && dv<grid[0].size() && grid[du][dv]==1){
                curr+=dfs(grid,du,dv);
            }
        }
        return curr;
    }
    int bfs(vector<vector<int>>& grid,int i,int j){
        int curr=0;
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j]=2;
        int u,v;
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            curr++;
            for(const auto [dx,dy] : coordinates){
                u=x+dx;
                v=y+dy;
                if(u>=0 && u<grid.size() && v<grid[0].size() && v>=0 && grid[u][v]==1){
                    q.push({u,v});
                    grid[u][v]=2;
                }
            }
        }
        return curr;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // can do with bfs
        int m=grid.size(),n=grid[0].size(),ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    // ans=max(ans,bfs(grid,i,j));
                    ans=max(ans,dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
};