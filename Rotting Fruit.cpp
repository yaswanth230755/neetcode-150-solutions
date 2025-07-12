class Solution {
    vector<pair<int,int>> directions={{-1,0},{1,0},{0,1},{0,-1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),count=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]){
                    count++;
                }
            }
        }
        if(!count){
            return 0;
        }
        int u,v,time=-1,len;
        while(!q.empty()){
            len=q.size();
            while(len--){
                const auto [x,y]=q.front();
                q.pop();
                for(const auto& [dx,dy] : directions){
                    u=x+dx;
                    v=y+dy;
                    if(u>=0 && u<m && v>=0 && v<n && grid[u][v]==1){
                        q.push({u,v});
                        grid[u][v]=2;
                        count--;
                    }
                }
            }
            time++;
        }
        if(!count){
            return time;
        }
        return -1;
    }
};