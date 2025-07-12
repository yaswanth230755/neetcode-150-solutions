class Solution {
    void construct(vector<int>& candidates,int index,int target,vector<int>& subans,vector<vector<int>>& ans){
        if(!target){
            ans.push_back(subans);
            return ;
        }
        if(index==candidates.size() || target<0){
            return ;
        }
        subans.push_back(candidates[index]);
        construct(candidates,index,target-candidates[index],subans,ans);
        subans.pop_back();
        construct(candidates,index+1,target,subans,ans);
    }
    void dfs(int i, vector<int> cur, int total, vector<int>& nums, int target,vector<vector<int>>& res) {
        if (total == target) {
            res.push_back(cur);
            return;
        }
        
        for (int j = i; j < nums.size(); j++) {
            if (total + nums[j] > target) {
                return;
            }
            cur.push_back(nums[j]);
            dfs(j, cur, total + nums[j], nums, target,res);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // vector<vector<int>> ans;
        // vector<int> subans;
        // construct(candidates,0,target,subans,ans);
        // return ans;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        dfs(0, {}, 0, candidates, target,res);
        return res;
    }
};