class Solution {
    bool check(int i,int j,vector<vector<char>>& board,const string& word,int index,const int& m,const int& n){
        if(index==word.length()){
            return true;
        }
        if(i==-1 || j==-1 || i==m || j==n || board[i][j]!=word[index]){
            return false;
        }
        char ch=board[i][j];
        board[i][j]='*';
        bool flag= check(i+1,j,board,word,index+1,m,n) || check(i,j+1,board,word,index+1,m,n) || check(i-1,j,board,word,index+1,m,n) || check(i,j-1,board,word,index+1,m,n);
        board[i][j]=ch;
        return flag;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && check(i,j,board,word,0,m,n)){
                    return true;
                }
            }
        }
        return false;
    }
};