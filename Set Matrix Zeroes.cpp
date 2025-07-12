class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        // int m = matrix.size(), n = matrix[0].size();
        // bool isrow = false, iscol = false;

        // // Step 1: Check if first column has any zero
        // for (int i = 0; i < m; i++) {
        //     if (matrix[i][0] == 0) {
        //         iscol = true;
        //         break;
        //     }
        // }

        // // Step 2: Check if first row has any zero
        // for (int j = 0; j < n; j++) {
        //     if (matrix[0][j] == 0) {
        //         isrow = true;
        //         break;
        //     }
        // }

        // // Step 3: Use first row and column as markers
        // for (int i = 1; i < m; i++) {
        //     for (int j = 1; j < n; j++) {
        //         if (matrix[i][j] == 0) {
        //             matrix[i][0] = 0;
        //             matrix[0][j] = 0;
        //         }
        //     }
        // }

        // // Step 4: Set zeroes based on markers (reversed inner loop is optional)
        // for (int i = 1; i < m; i++) {
        //     for (int j = n - 1; j >= 1; j--) {
        //         if (matrix[i][0] == 0 || matrix[0][j] == 0) {
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }

        // // Step 5: Zero out first row if needed
        // if (isrow) {
        //     for (int j = 0; j < n; j++) {
        //         matrix[0][j] = 0;
        //     }
        // }

        // // Step 6: Zero out first column if needed
        // if (iscol) {
        //     for (int i = 0; i < m; i++) {
        //         matrix[i][0] = 0;
        //     }
        // }

        int m=matrix.size(),n=matrix[0].size();
        bool isrow=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    if(i==0){
                        isrow=true;
                    }
                    else{
                        matrix[i][0]=0;
                    }
                    matrix[0][j]=0;
                }
            }
        }

        // below can also done by i from m to 0 and j from n-1 to 0
        for(int i=1;i<m;i++){
                for(int j=n-1;j>=0;j--){ // think why in reverse order
                   if(matrix[i][0]==0 || matrix[0][j]==0){
                        matrix[i][j]=0;
                   }
                }
            }
            if(isrow){
                for(int j=0;j<n;j++){
                    matrix[0][j]=0;
                }
            }
    }
};
