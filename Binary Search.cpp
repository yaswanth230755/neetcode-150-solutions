class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Lower Bound (not inbuilt)
        // Upper Bound (not inbuilt)
        // int start=0,end=nums.size()-1,mid;
        // while(start<=end){
        //     mid=start+((end-start)>>1);
        //     if(nums[mid]==target){
        //         return mid;
        //     }
        //     else if(nums[mid]>target){
        //         end=mid-1;
        //     }
        //     else{
        //         start=mid+1;
        //     }
        // }
        // return -1;
        auto it=lower_bound(nums.begin(),nums.end(),target);
        return (it!=nums.end() && *it==target)?it-nums.begin():-1;
    }
};