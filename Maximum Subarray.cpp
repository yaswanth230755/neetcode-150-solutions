class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max=INT_MIN,n=nums.size(),curr=0;
        for(int i=0;i<n;i++){
            curr+=nums[i];
            if(curr<nums[i]){
                curr=nums[i];
            }
            max=std::max(max,curr);

            // if(curr<0){
            //     curr=0;
            // }
            // curr+=nums[i];
            // max=std::max(max,curr);
        }
        return max;
    }
};