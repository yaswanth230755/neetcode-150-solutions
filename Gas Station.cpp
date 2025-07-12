class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(),fuel=0,ispossible=0,start=0;
        for(int i=0;i<n;i++){
            fuel+=gas[i]-cost[i];
            if(fuel<0){
                start=i+1;
                fuel=0;
            }
            ispossible+=gas[i]-cost[i];
        }
        return (ispossible>=0)?start:-1;
    }
};