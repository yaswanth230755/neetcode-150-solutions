class Solution {
    vector<pair<int,int>> directions={{-1,0},{1,0},{0,1},{0,-1}};
    void dfs(vector<vector<char>>& board,int i,int j){
        board[i][j]='Y';
        int u,v;
        for(const auto& [dx,dy] : directions){
            u=i+dx;
            v=j+dy;
            if(u>=0 && u<board.size() && v>=0 && v<board[0].size() && board[u][v]=='O'){
                dfs(board,u,v);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                //dfs(board,i,0);
                q.push({i,0});
                board[i][0]='Y';
            }
            if(board[i][n-1]=='O'){
                //dfs(board,i,n-1);
                q.push({i,n-1});
                board[i][n-1]='Y';
            }
        }
        for(int i=1;i<n-1;i++){
            if(board[0][i]=='O'){
                //dfs(board,0,i);
                q.push({0,i});
                board[0][i]='Y';
            }
            if(board[m-1][i]=='O'){
                //dfs(board,m-1,i);
                q.push({m-1,i});
                board[m-1][i]='Y';
            }
        }


        int u,v;
        while(!q.empty()){
            const auto [x,y]=q.front();
            q.pop();
            for(const auto& [dx,dy] : directions){
                u=x+dx;
                v=y+dy;
                if(u>=0 && u<board.size() && v>=0 && v<board[0].size() && board[u][v]=='O'){
                    q.push({u,v});
                    board[u][v]='Y';
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='Y'){
                    board[i][j]='O';
                }
            }
        }
    }
};