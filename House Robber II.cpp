class Solution {
    int rob1(vector<int>& nums) {
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
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        int temp=0;
        swap(nums[n-1],temp);
        int first=rob1(nums);
        swap(nums[n-1],temp);
        swap(nums[0],temp);
        int second=rob1(nums);
        swap(nums[0],temp);
        return max(first,second);
    }
};