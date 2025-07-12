class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // sort + two pointer approach
        // unordered_map<int ,int> unmap;

        // int i=0,j=nums.size()-1,currSum,n=nums.size();
        // vector<pair<int,int>> v;
        // for(int i=0;i<n;i++){
        //     v.push_back({nums[i],i});
        // }
        // sort(v.begin(),v.end());
        // while(i<j){
        //     currSum=v[i].first+v[j].first;
        //     if(currSum==target){
        //         return {v[i].second,v[j].second};
        //     }
        //     else if(currSum<target){
        //         i++;
        //     }
        //     else{
        //         j--;
        //     }
        // }
        // return {-1,-1};

        unordered_map<int ,int> unmap;
        int n=nums.size();
        for(int i=0;i<n;i++){
            auto it=unmap.find(target-nums[i]);
            if(it!=unmap.end()){
                return {it->second,i};
            }
            unmap.insert({nums[i],i});
        }
        return {-1,-1};
    }
};