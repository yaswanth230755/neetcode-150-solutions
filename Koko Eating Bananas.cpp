class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // int l = 1;
        // int r = *max_element(piles.begin(), piles.end());
        // int res = r;
        // while (l <= r) {
        //     int k = (l + r) / 2;
        //     long long totalTime = 0;
        //     for (int p : piles) {
        //         totalTime += ceil(static_cast<double>(p) / k);
        //     }
        //     if (totalTime <= h) {
        //         res = k;
        //         r = k - 1;
        //     } else {
        //         l = k + 1;
        //     }
        // }
        // return res;


        int min=1,max=INT_MIN;
        long long sum=0;
        for(const auto& pile : piles){
            sum+=pile;
            max=std::max(max,pile);
        }
        min=std::max(min,(int)(sum/h));
        int mid,count;
        while(min<max){
            mid=min+((max-min)>>1);
            count=0;
            for(const auto& pile : piles){
                count+=pile/mid;
                if(pile%mid){
                    count++;
                }
            }
            if(count>h){
                min=mid+1;
            }
            else{
                max=mid;
            }
        }
        return min;
    }
};