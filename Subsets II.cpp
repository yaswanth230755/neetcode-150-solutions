class Solution {
    void construct(vector<int>& nums,int index,vector<int>& subset,vector<vector<int>>& ans){
        if(index==nums.size()){
            ans.push_back(subset);
            return ;
        }
        subset.push_back(nums[index]);
        construct(nums,index+1,subset,ans);
        subset.pop_back();
        while(index+1<nums.size() && nums[index]==nums[index+1]){
            index++;
        }
        construct(nums,index+1,subset,ans);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> subset;
        vector<vector<int>> ans;
        construct(nums,0,subset,ans);
        return ans;

        // sort(nums.begin(), nums.end());
        // vector<vector<int>> res = {{}};
        // int prevIdx = 0;
        // int idx = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     idx = (i >= 1 && nums[i] == nums[i - 1]) ? prevIdx : 0;
        //     prevIdx = res.size();
        //     for (int j = idx; j < prevIdx; j++) {
        //         std::vector<int> tmp = res[j];
        //         tmp.push_back(nums[i]);
        //         res.push_back(tmp);
        //     }
        // }
        // return res;
    }
};