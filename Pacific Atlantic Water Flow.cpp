class Solution {
    vector<pair<int,int>> directions={{-1,0},{1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>>& height,int i,int j,vector<vector<bool>>& both){
        both[i][j]=true;
        int u,v;
        for(const auto& [dx,dy] : directions){
            u=i+dx;
            v=j+dy;
            if(u>=0 && u<height.size() && v>=0 && v<height[0].size() && height[i][j]<=height[u][v] && !both[u][v]){
                dfs(height,u,v,both);
            }
        }
    }
    void bfs(vector<vector<int>>& height,queue<pair<int,int>>& q,vector<vector<bool>>& both){
        int u,v;
        while(!q.empty()){
            const auto [i,j]=q.front();
            q.pop();
            for(const auto& [dx,dy] : directions){
                u=i+dx;
                v=j+dy;
                if(u>=0 && u<height.size() && v>=0 && v<height[0].size() && height[i][j]<=height[u][v] && !both[u][v]){
                    dfs(height,u,v,both);
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));
        queue<pair<int,int>> pacificq,atlanticq;

        for(int i=0;i<m;i++){
            // dfs(heights,i,0,pacific);
            // dfs(heights,i,n-1,atlantic);
            pacificq.push({i,0});
            pacific[i][0]=true;
            atlanticq.push({i,n-1});
            atlantic[i][n-1]=true;
        }
        for(int i=0;i<n;i++){
            // dfs(heights,0,i,pacific);
            // dfs(heights,m-1,i,atlantic);
            pacificq.push({0,i});
            pacific[0][i]=true;
            atlanticq.push({m-1,i});
            atlantic[m-1][i]=true;
        }
        bfs(heights,pacificq,pacific);
        bfs(heights,atlanticq,atlantic);

        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};