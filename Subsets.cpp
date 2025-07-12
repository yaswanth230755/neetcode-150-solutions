class Solution {
    void construct(vector<int>&  nums,int index,vector<int>& subset,vector<vector<int>>& ans){
        if(index==nums.size()){
            ans.push_back(subset);
            return ;
        }
        subset.push_back(nums[index]);
        construct(nums,index+1,subset,ans);
        subset.pop_back();
        construct(nums,index+1,subset,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // vector<vector<int>> ans;
        // vector<int> subset;
        // construct(nums,0,subset,ans);
        // return ans;


        // vector<vector<int>> ans;
        // vector<int> subset;
        // int n=nums.size(),number=1<<n;
        // for(int i=0;i<number;i++){
        //     for(int j=0;j<n;j++){
        //         if(i&(1<<j)){
        //             subset.push_back(nums[j]);
        //         }
        //     }
        //     ans.push_back(subset);
        //     subset={};
        // }
        // return ans;


        vector<vector<int>> ans;
        vector<int> copy;
        int n=1;
        ans.push_back({});
        for(const int& num : nums){
            for(int i=0;i<n;i++){
                copy=ans[i];
                copy.push_back(num);
                ans.push_back(copy);// size of ans increases not constant
            }
            n<<=1;
        }
        return ans;
    }
};