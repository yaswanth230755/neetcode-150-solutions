class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,int>> pq;
        int distance,n=points.size();
        for(int i=0;i<n;i++){
            distance=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            if(pq.size()<k || pq.top().first>distance){
                pq.push({distance,i});
            }
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};