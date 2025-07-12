class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int il=0,ih=matrix.size()-1,jl=0,jh=matrix[0].size()-1,im,jm;
        while(il<=ih){
            im=il+((ih-il)>>1);
            if(matrix[im][0]<=target && matrix[im][jh]>=target){
                break;
            }
            else if(matrix[im][0]>target){
                ih=im-1;
            }
            else{
                il=im+1;
            }
        }
        if(il>ih){
            return false;
        }
        while(jl<=jh){
            jm=jl+((jh-jl)>>1);
            if(matrix[im][jm]==target){
                return true;
            }
            else if(matrix[im][jm]<target){
                jl=jm+1;
            }
            else{
                jh=jm-1;
            }
        }
        return false;



        // int ROWS = matrix.size(), COLS = matrix[0].size();
        // int l = 0, r = ROWS * COLS - 1;
        // while (l <= r) {
        //     int m = l + (r - l) / 2;
        //     int row = m / COLS, col = m % COLS;
        //     if (target > matrix[row][col]) {
        //         l = m + 1;
        //     } else if (target < matrix[row][col]) {
        //         r = m - 1;
        //     } else {
        //         return true;
        //     }
        // }
        // return false;


        // int m = matrix.size(), n = matrix[0].size();
        // int r = 0, c = n - 1;
        // while (r < m && c >= 0) {
        //     if (matrix[r][c] > target) {
        //         c--;
        //     } else if (matrix[r][c] < target) {
        //         r++;
        //     } else {
        //         return true;
        //     }
        // }
        // return false;
    }
};