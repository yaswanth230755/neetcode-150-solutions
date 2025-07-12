class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool isx=false,isy=false,isz=false;
        for(const auto& triplet : triplets){
            if(triplet[0]<=target[0] && triplet[1]<=target[1] & triplet[2]<=target[2]){         
                if(!isx){
                    isx=isx || triplet[0]==target[0];
                }
                if(!isy){
                    isy=isy || triplet[1]==target[1];
                }
                if(!isz){
                    isz=isz || triplet[2]==target[2];
                }
            }
        }
        return isx && isy && isz;
    }
};