class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // 1D dp
        const long MOD = INT_MAX+1;
        int n = coins.size();
        vector<long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] = (dp[j] + dp[j - coins[i]]) % MOD;
            }
        }

        return dp[amount];


       // 2D dp
        // const long MOD = INT_MAX+1;
        // int n=coins.size();
        // vector<vector<long>> dp(n,vector<long>(amount+1,0));
        // for(int i=0;i<=amount;i++){
        //     if(i%coins[0]==0){
        //         dp[0][i]=1;
        //     }
        // }
        // int take,nottake;
        // for(int i=1;i<n;i++){
        //     for(int j=0;j<=amount;j++){
        //         nottake=dp[i-1][j];
        //         take=0;
        //         if(coins[i]<=j){
        //             take=dp[i][j-coins[i]];
        //         }
        //         dp[i][j]=(dp[i][j]+nottake+take)% MOD;
        //     }
        // }
        // return dp[n-1][amount];
    }
};
