class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // multiply with -1
        // vector (n+1)
        
        // int slow = 0, fast = 0;
        // while (true) {
        //     slow = nums[slow];
        //     fast = nums[nums[fast]];
        //     if (slow == fast) {
        //         break;
        //     }
        // }

        // int slow2 = 0;
        // while (true) {
        //     slow = nums[slow];
        //     slow2 = nums[slow2];
        //     if (slow == slow2) {
        //         return slow;
        //     }
        // }


        for(const auto& num : nums){
            if(nums[abs(num)-1]<0){
                return abs(num);
            }
            nums[abs(num)-1]=-nums[abs(num)-1];
        }
        return -1;
    }
};