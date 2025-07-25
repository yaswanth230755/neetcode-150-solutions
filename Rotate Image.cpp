class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose and reverse
        int n=matrix.size();
        reverse(matrix.begin(),matrix.end());
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};
