class Solution {
public:
    int findMin(vector<int>& nums) {
        // int l = 0, r = nums.size() - 1;
        // while (l < r) {
        //     int m = l + (r - l) / 2;
        //     if (nums[m] < nums[r]) {
        //         r = m;
        //     } else {
        //         l = m + 1;
        //     }
        // }
        // return nums[l];



        int l=0,h=nums.size()-1,m;
        while(l<h){
            m=l+((h-l)>>1);
            if(nums[m]<nums[h]){
                h=m;
            }
            else{
                l=m+1;
            }
        }
        return nums[l];
    }
};