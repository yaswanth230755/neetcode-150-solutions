class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // int sum=accumulate(digits.begin(),digits.end(),0),n=digits.size();
        // if(sum/n==9){
        //     for(int& var : digits){
        //         var=0;
        //     }
        //     digits[0]=1;
        //     digits.push_back(0);
        // }
        // else{
        //     int carry=1,sum;
        //     for(int i=n-1;i>=0;i--){
        //         sum=digits[i]+carry;
        //         digits[i]=sum%10;
        //         carry=sum/10;
        //         if(carry==0)
        //             break;
        //     }
        // }
        // return digits;


        int one = 1;
        int i = 0;
        reverse(digits.begin(), digits.end());

        while (one) {
            if (i < digits.size()) {
                if (digits[i] == 9) {
                    digits[i] = 0;
                } else {
                    digits[i] += 1;
                    one = 0;
                }
            } else {
                digits.push_back(one);
                one = 0;
            }
            i++;
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
