class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        int i=2,first=nums[0],second=max(nums[0],nums[1]),temp;
        while(i<n){
            temp=max(second,first+nums[i]);
            first=second;
            second=temp;
            i++;
        }
        return max(second,first);
    }
};