class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<>> pq;
        for(const int& num : nums){
            if(pq.size()<k || pq.top()<num){
                pq.push(num);
            }
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};