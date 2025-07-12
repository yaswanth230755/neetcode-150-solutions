class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // unordered_set (best in practice)
        // unordered_map

        // unordered_map<int,int> unmap;
        // int max=0;
        // for(const auto& num : nums){
        //     if(!unmap[num]){
        //         unmap[num]=unmap[num-1]+unmap[num+1]+1;
        //         unmap[num-unmap[num-1]]=unmap[num];
        //         unmap[num+unmap[num+1]]=unmap[num];
        //         max=std::max(max,unmap[num]);
        //     }
        // }
        // return max;


        unordered_set<int> unset(nums.begin(),nums.end());
        int max=0,curr;
        for(const int& num : unset){
            if(!unset.count(num-1)){
                curr=1;
                while(unset.count(num+curr)){
                    curr++;
                }
                max=std::max(max,curr);
            }
        }
        return max;
    }
};