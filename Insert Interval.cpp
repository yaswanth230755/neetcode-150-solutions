class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // TC :O(n) SC: O(n)
        // vector<vector<int>> ans;
        // int i,n=intervals.size(),index=-1;
        // for(i=0;i<n;i++){
        //     if(intervals[i][0]>newInterval[0]){
        //         break;
        //     }
        //     ans.push_back(intervals[i]);
        //     index++;
        // }
        // if(index>=0 && ans[index][1]>=newInterval[0]){
        //     ans[index][1]=max(ans[index][1],newInterval[1]);
        // }
        // else{
        //     ans.push_back(newInterval);
        //     index++;
        // }
        // for(;i<n;i++){
        //     if(ans[index][1]>=intervals[i][0]){
        //         ans[index][1]=max(ans[index][1],intervals[i][1]);
        //     }
        //     else{
        //         ans.push_back(intervals[i]);
        //         index++;
        //     }
        // }
        // return ans;




        vector<vector<int>> ans;
        int i = 0, n = intervals.size();

        // 1. Add all intervals before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i++]);
        }

        // 2. Merge overlapping intervals with newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        // 3. Add remaining intervals
        while (i < n) {
            ans.push_back(intervals[i++]);
        }

        return ans;
    }
};
