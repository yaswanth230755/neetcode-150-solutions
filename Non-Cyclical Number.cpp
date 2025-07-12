class Solution {
    int sumOfSquares(int n) {
        int output = 0;
        while (n != 0) {
            output += (n % 10) * (n % 10);
            n /= 10;
        }
        return output;
    }
public:
    bool isHappy(int n) {
        // unordered_set<int> unset;
        // int temp=n;
        // while(n!=1){
        //     if(unset.find(n)!=unset.end())
        //         return false;
        //     unset.insert(n);
        //     temp=n;
        //     n=0;
        //     while(temp){
        //         n+=(temp%10)*(temp%10);
        //         temp/=10;
        //     }
        // }
        // return true;


        // int slow = n, fast = sumOfSquares(n);

        // while (slow != fast) {
        //     fast = sumOfSquares(fast);
        //     fast = sumOfSquares(fast);
        //     slow = sumOfSquares(slow);
        // }

        // return fast == 1;



        int slow = n, fast = sumOfSquares(n);
        int power = 1, lam = 1;

        while (slow != fast) {
            if (power == lam) {
                slow = fast;
                power *= 2;
                lam = 0;
            }
            lam++;
            fast = sumOfSquares(fast);
        }

        return fast == 1;
    }
};
