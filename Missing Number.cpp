class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // can sort;
        // can also use unordermap or array
        // can also use multiply with -1 
        // can find sum
        int x,n=nums.size();
        if (n % 4 == 0) 
        x=n;
        else if (n % 4 == 1) 
        x=1;
        else if (n % 4 == 2) 
        x=n + 1;
        else 
        x=0;
        int sum=(n*(n+1)>>1);
        for(const int& var : nums){
            x^=var;
            sum-=var;
        }
        return sum;
        return x;
    }
};
