class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // sort(nums.begin(), nums.end());
        // unordered_map<int, int> count;
        // for (int num : nums) {
        //     count[num]++;
        // }

        // vector<vector<int>> res;
        // for (int i = 0; i < nums.size(); i++) {
        //     count[nums[i]]--;
        //     if (i > 0 && nums[i] == nums[i - 1]) continue;

        //     for (int j = i + 1; j < nums.size(); j++) {
        //         count[nums[j]]--;
        //         if (j > i + 1 && nums[j] == nums[j - 1]) continue;

        //         int target = -(nums[i] + nums[j]);
        //         if (count[target] > 0) {
        //             res.push_back({nums[i], nums[j], target});
        //         }
        //     }

        //     for (int j = i + 1; j < nums.size(); j++) {
        //         count[nums[j]]++;
        //     }
        // }

        // return res;

        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size(),currSum,j,k;
        for(int i=0;i<n-2;i++){
            j=i+1;
            k=n-1;
            while(j<k){
                currSum=nums[i]+nums[j]+nums[k];
                if(currSum==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j+1<k && nums[j]==nums[j+1]){
                        j++;
                    }
                    while(j<k-1 && nums[k]==nums[k-1]){
                        k--;
                    }
                    j++;
                    k--;
                }
                else if(currSum>0){
                    k--;
                }
                else{
                    j++;
                }
            }
            while(i+1<n-2 && nums[i]==nums[i+1]){
                i++;
            }
        }
        return ans;
    }
};