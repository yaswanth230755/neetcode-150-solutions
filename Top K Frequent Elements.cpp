class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // bucket sort why because freq of a element can not exceed nums.size()
        // get freq of each ele then sort accor to freq using vector of pairs or multimap or minheap

        unordered_map<int,int> unmap;
        for(const auto& num : nums){
            unmap[num]++;
        }
        int n=nums.size();
        vector<list<int>> freq(n+1);
        for(const auto& ele : unmap){
            freq[ele.second].push_front(ele.first);
        }
        vector<int> ans;
        for(int i=n;i>=0 && k;i--){
            for(auto it=freq[i].begin();it!=freq[i].end() && k--;it++){
                ans.push_back(*it);
            }
        }
        return ans;

        // unordered_map<int,int> unmap;
        // for(const auto& num : nums){
        //     unmap[num]++;
        // }
        // vector<pair<int,int>> p;
        // for(const auto& ele : unmap){
        //     p.push_back({ele.second,ele.first});
        // }
        // sort(p.begin(),p.end());
        // vector<int> ans;
        // for(auto it=p.rbegin();it!=p.rend() && k--;it++){
        //     ans.push_back(it->second);
        // }
        // return ans;
    }
};