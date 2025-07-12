class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // int l = 0, r = 1;
        // int maxP = 0;
        // while (r < prices.size()) {
        //     if (prices[l] < prices[r]) {
        //         int profit = prices[r] - prices[l];
        //         maxP = max(maxP, profit);
        //     } else {
        //         l = r;
        //     }
        //     r++;
        // }
        // return maxP;

        int n=prices.size(),rightMax=prices[n-1],maxProfit=0;
        for(int i=n-2;i>=0;i--){
            maxProfit=max(maxProfit,rightMax-prices[i]);
            rightMax=max(rightMax,prices[i]);
        }
        return maxProfit;
    }
};