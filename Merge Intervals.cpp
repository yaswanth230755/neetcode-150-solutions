class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // can do using O(1000) SC


        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int lastIn=-1,i=0,n=intervals.size();
        while(i<n){
            if(lastIn>=0 && ans[lastIn][1]>=intervals[i][0]){
                ans[lastIn][0]=min(ans[lastIn][0],intervals[i][0]);
                ans[lastIn][1]=max(ans[lastIn][1],intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
                lastIn++;
            }
            i++;
        }
        return ans;
    }
};
