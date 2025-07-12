class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // use sorting when find and insert in unordered set is O(n)
        
        return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();

        // unordered_set<int> unset;
        // for(const auto& num : nums){
        //     if(unset.find(num)!=unset.end()){
        //         return true;
        //     }
        //     unset.insert(num);
        // }
        // return false;

        // sort(nums.begin(), nums.end());
        // for (int i = 1; i < nums.size(); ++i) {
        //     if (nums[i] == nums[i - 1]) return true;
        // }
        // return false;
    }
};
