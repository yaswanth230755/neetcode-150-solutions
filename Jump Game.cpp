class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJumpablePos=0,n=nums.size();
        for(int i=0;i<n-1;i++){
            if(i>maxJumpablePos){
                return false;
            }
            maxJumpablePos=max(maxJumpablePos,nums[i]+i);
            if(maxJumpablePos>=n-1){
                return true;
            }
        }
        return maxJumpablePos>=n-1;


        // int n=nums.size();
        // vector<bool> dp(n,false);
        // dp[0]=true;
        // int j;
        // for(int i=0;i<n-1;i++){
        //     if(!dp[i])
        //     return false;
        //     j=nums[i]+i;
        //     while(j>i && !dp[j]){
        //         dp[j]=true;
        //         j--;
        //     }
        // }
        // return dp[n-1];
    }
};
