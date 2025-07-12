class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),prefix=1,suffix=1,max=INT_MIN;
        for(int i=0;i<n;i++){
            prefix*=nums[i];
            suffix*=nums[n-1-i];
            max=std::max(max,std::max(prefix,suffix));
            if(!prefix){
                prefix=1;
            }
            if(!suffix){
                suffix=1;
            }
        }
        return max;
    }
};