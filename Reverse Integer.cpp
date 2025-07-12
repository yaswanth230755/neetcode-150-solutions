class Solution {
public:
    int reverse(int x) {
        
        // long long result = 0;
        // while (x != 0) {
        //     result = result * 10 + x % 10;
        //     x /= 10;
        // }
        // // Check if result is within 32-bit signed integer range
        // if (result > INT_MAX || result < INT_MIN) {
        //     return 0;
        // }
        // return (int)result;
        

        // const int MIN = -2147483648; // -2^31
        // const int MAX = 2147483647;  // 2^31 - 1

        // int res = 0;
        // while (x != 0) {
        //     int digit = x % 10;
        //     x /= 10;

        //     if (res > MAX / 10 || (res == MAX / 10 && digit > MAX % 10))
        //         return 0;
        //     if (res < MIN / 10 || (res == MIN / 10 && digit < MIN % 10))
        //         return 0;
        //     res = (res * 10) + digit;
        // }

        // return res;


        string str = to_string(abs(x));
        std::reverse(str.begin(), str.end());
        
        // Check for overflow before converting
        if (str.length() > 10 || 
            (str.length() == 10 && str > "2147483648")) {
            return 0;
        }
        if(str=="2147483648"){
            if(x<0)
                return INT_MIN;
            else
                return 0;
        }
        if(x>=0)
        return stoi(str);
        return -stoi(str);
    }
};