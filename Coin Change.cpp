class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1e6);
        dp[0] = 0;  // base case: 0 coins to make amount 0

        for (int coin : coins) {
            for (int j = coin; j <= amount; ++j) {
                dp[j] = min(dp[j], 1 + dp[j - coin]);
            }
        }

        return dp[amount] >= 1e6 ? -1 : dp[amount];



        // int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount + 1, 1e6));
        // // Base case: using only the first coin
        // for (int j = 0; j <= amount; ++j) {
        //     if (j % coins[0] == 0) {
        //         dp[0][j] = j / coins[0];
        //     }
        // }
        // for (int i = 1; i < n; ++i) {
        //     for (int j = 0; j <= amount; ++j) {
        //         // Option 1: don't take the coin
        //         int notTake = dp[i - 1][j];
        //         // Option 2: take the coin (only if coin[i] ≤ j)
        //         int take = 1e6;
        //         if (coins[i] <= j) {
        //             take = 1 + dp[i][j - coins[i]]; // take and stay at i (unlimited supply)
        //         }
        //         dp[i][j] = min(take, notTake);
        //     }
        // }
        // return dp[n - 1][amount] >= 1e6 ? -1 : dp[n - 1][amount];

    }
};
