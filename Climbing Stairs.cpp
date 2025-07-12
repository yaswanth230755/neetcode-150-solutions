class Solution {
public:
    int climbStairs(int n) {
        // see optimised sol
         if(n==1 || n==2){
            return n;
         }
         int first=1,second=2,ans;
         for(int i=2;i<n;i++){
            ans=first+second;
            first=second;
            second=ans;
         }
         return ans;
    }
};
