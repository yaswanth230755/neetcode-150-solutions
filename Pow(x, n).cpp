class Solution {
public:
    double myPow(double x, int n) {
        // can use binary search for sqrt from 1 to n
        // then binar seach break when mid*mid=n

        if (x == 0) return 0;
        if (n == 0) return 1;

        double res = 1;
        long power = abs((long)n);

        while (power) {
            if (power & 1) {
                res *= x;
            }
            x *= x;
            power >>= 1;
        }

        return n >= 0 ? res : 1 / res;
        

        // if (x == 0) 
        //     return 0;
        // if(n==0)
        //     return 1;
        // if(abs(n)&1){
        //     if(n>0){
        //         return myPow(x,n/2)*myPow(x,n/2)*x;
        //     }
        //     else{
        //         return myPow(x,n/2)*myPow(x,n/2)/x;
        //     }
        // }
        // else{
        //     return myPow(x,n/2)*myPow(x,n/2);
        // }
    }
};
