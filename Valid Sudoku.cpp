class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // unordered_set or array or bitmasking
        vector<int> rows(9,0);
        vector<int> cols(9,0);
        vector<int> boxs(9,0);
        char ch;
        int index,bit;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                    continue;
                bit = (1 << (board[i][j] - '1'));
                index=i/3+3*(j/3);
                if(( rows[i] & bit ) || ( cols[j] & bit) || ( boxs[index] & bit) ){
                    return false;
                }
                rows[i]|=bit;
                cols[j]|=bit;
                boxs[index]|=bit;
            }
        }
        return true;
        

        // vector<vector<bool>> rows(9,vector<bool>(9,false));
        // vector<vector<bool>> cols(9,vector<bool>(9,false));
        // vector<vector<bool>> boxs(9,vector<bool>(9,false));
        // char ch;
        // int index;
        // for(int i=0;i<9;i++){
        //     for(int j=0;j<9;j++){
        //         if(board[i][j]=='.')
        //             continue;
        //         ch=board[i][j];
        //         index=i/3+3*(j/3);
        //         if(rows[i][ch-'1'] || cols[j][ch-'1'] || boxs[index][ch-'1']){
        //             return false;
        //         }
        //         rows[i][ch-'1']=true;
        //         cols[j][ch-'1']=true;
        //         boxs[index][ch-'1']=true;
        //     }
        // }
        // return true;


        // vector<unordered_set<char>> rows(9);
        // vector<unordered_set<char>> cols(9);
        // vector<unordered_set<char>> boxs(9);
        // char ch;
        // int index;
        // for(int i=0;i<9;i++){
        //     for(int j=0;j<9;j++){
        //         if(board[i][j]=='.')
        //             continue;
        //         ch=board[i][j];
        //         index=i/3+3*(j/3);
        //         if(rows[i].find(ch)!=rows[i].end() || cols[j].find(ch)!=cols[j].end() || boxs[index].find(ch)!=boxs[index].end()){
        //             return false;
        //         }
        //         rows[i].insert(ch);
        //         cols[j].insert(ch);
        //         boxs[index].insert(ch);
        //     }
        // }
        // return true;
    }
};