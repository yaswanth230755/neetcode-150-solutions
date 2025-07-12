class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1,currSum;
        while(i<j){
            currSum=numbers[i]+numbers[j];
            if(currSum==target){
                return {i+1,j+1};
            }
            else if(currSum>target){
                j--;
            }
            else{
                i++;
            }
        }
        return {};
    }
};