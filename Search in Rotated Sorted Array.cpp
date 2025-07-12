class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int l = 0, r = nums.size() - 1;
        // while (l <= r) {
        //     int mid = (l + r) / 2;
        //     if (target == nums[mid]) {
        //         return mid;
        //     }
        //     if (nums[l] <= nums[mid]) {
        //         if (target > nums[mid] || target < nums[l]) {
        //             l = mid + 1;
        //         } else {
        //             r = mid - 1;
        //         }
        //     } else {
        //         if (target < nums[mid] || target > nums[r]) {
        //             r = mid - 1;
        //         } else {
        //             l = mid + 1;
        //         }
        //     }
        // }
        // return -1;



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
        auto it=lower_bound(nums.begin()+l,nums.end(),target);
        if(it!=nums.end() && *it==target){
            return it-nums.begin();
        }
        it=lower_bound(nums.begin(),nums.begin()+l,target);
        if(it!=nums.end() && *it==target){
            return it-nums.begin();
        }
        return -1;
    }
};