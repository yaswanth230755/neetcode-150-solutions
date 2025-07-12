class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size(),first=cost[0],second=cost[1],temp,i=2;
        while(i<n){
            temp=min(first,second)+cost[i];
            first=second;
            second=temp;
            i++;
        }
        return min(second,first);
    }
};