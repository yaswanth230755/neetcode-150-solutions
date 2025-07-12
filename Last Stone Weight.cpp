class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // int maxStone = 0;
        // for (int stone : stones) {
        //     maxStone = max(maxStone, stone);
        // }
        // vector<int> bucket(maxStone + 1, 0);
        // for (int stone : stones) {
        //     bucket[stone]++;
        // }
        // int first = maxStone, second = maxStone;
        // while (first > 0) {
        //     if (bucket[first] % 2 == 0) {
        //         first--;
        //         continue;
        //     }
        //     int j = min(first - 1, second);
        //     while (j > 0 && bucket[j] == 0) {
        //         j--;
        //     }
        //     if (j == 0) {
        //         return first;
        //     }
        //     second = j;
        //     bucket[first]--;
        //     bucket[second]--;
        //     bucket[first - second]++;
        //     first = max(first - second, second);
        // }
        // return first;


        priority_queue<int> pq(stones.begin(),stones.end());
        int first,second;
        while(pq.size()>1){
            first=pq.top();
            pq.pop();
            second=pq.top();
            pq.pop();
            if(first!=second){
                pq.push(first-second);
            }
        }
        if(!pq.empty()){
            return pq.top();
        }
        return 0;
    }
};