class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // can use string or
        // while like reverse

        // string str;
        // int i=32;
        // while(i--){
        //     str+=to_string(n&1);
        //     n=n>>1;
        // }
        // uint32_t ans=0;
        // i=32;
        // while(i--){
        //     ans=ans<<1;
        //     ans+=str[31-i]-'0';
        // }
        // return ans;

        /*
        uint32_t ret = n;
        ret = (ret >> 16) | (ret << 16);
        ret = ((ret & 0xff00ff00) >> 8) | ((ret & 0x00ff00ff) << 8);
        ret = ((ret & 0xf0f0f0f0) >> 4) | ((ret & 0x0f0f0f0f) << 4);
        ret = ((ret & 0xcccccccc) >> 2) | ((ret & 0x33333333) << 2);
        ret = ((ret & 0xaaaaaaaa) >> 1) | ((ret & 0x55555555) << 1);
        return ret;
        */

        uint32_t ans=0;
        int i=32;
        while(i--){
            ans<<=1;
            ans|=n&1;
            n>>=1;
        }
        return ans;
    }
};
