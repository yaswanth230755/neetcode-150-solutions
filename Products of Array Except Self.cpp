class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1);
        // left product
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        // right product
        int right_product=nums[n-1];
        for(int i=n-2;i>=0;i--){
            ans[i]*=right_product;
            right_product*=nums[i];
        }
        return ans;
    }
};