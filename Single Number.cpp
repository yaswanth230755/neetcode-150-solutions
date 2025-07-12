class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        for(const int& var : nums){
            x^=var;
        }
        return x;
    }
};
