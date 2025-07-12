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
        construct(candidates,index+1,target-candidates[index],subans,ans);
        subans.pop_back();
        while(index+1<candidates.size() && candidates[index]==candidates[index+1]){
            index++;
        }
        construct(candidates,index+1,target,subans,ans);
    }
    void dfs(vector<int>& candidates,int index,int target,vector<int>& subans,vector<vector<int>>& ans){
        if(!target){
            ans.push_back(subans);
            return ;
        }
        if(index==candidates.size()){
            return ;
        }
        for(int i=index;i<candidates.size();i++){
            if(target-candidates[i]<0){
                return ;
            }
            subans.push_back(candidates[i]);
            dfs(candidates,i+1,target-candidates[i],subans,ans);
            subans.pop_back();
            while(i+1<candidates.size() && candidates[i]==candidates[i+1]){
                i++;
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sort(candidates.begin(),candidates.end());
        // vector<vector<int>> ans;
        // vector<int> subans;
        // construct(candidates,0,target,subans,ans);
        // return ans;


        sort(candidates.begin(),candidates.end());
        vector<int> subans;
        vector<vector<int>> ans;
        dfs(candidates,0,target,subans,ans);
        return ans;
    }
};