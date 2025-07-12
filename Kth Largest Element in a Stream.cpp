class KthLargest {
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
    // can sort
public:
    KthLargest(int k, vector<int>& nums) {
        // this->k=k;
        // for(const int& var : nums){
        //     pq.push(var);
        // }
        // while(pq.size()>k){
        //     pq.pop();
        // }


        this->k=k;
        for(const int& num : nums){
            if(pq.size()<k || pq.top()<num){
                pq.push(num);
            }
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        // pq.push(val);
        // if(pq.size()>k)
        //     pq.pop();
        // return pq.top();

        if(pq.size()<k || pq.top()<val){
            pq.push(val);
        }
        if(pq.size()>k){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */