class Solution {
    int arr[255];
    void fun(){
    arr[0]=0;
    for(int i=1;i<256;i++){
        arr[i]=arr[i>>1]+(i&1);
    }
    }
public:
    int hammingWeight(uint32_t n) {

        // int ans=0;
        // while(n){
        //     if(n&1)
        //         ans++;
        //     n=n>>1;
        // }
        // return ans;

        // int ans=0;
        // while(n){
        //     n=n&(n-1);
        //     ans++;
        // }
        // return ans;

        fun();
        //return arr[n&255]+arr[(n>>8)&255]+arr[(n>>16)&255]+arr[(n>>24)&255];
        return arr[n& 0xff]+arr[(n>>8)& 0xff]+arr[(n>>16)&0xff]+arr[(n>>24)&0xff];

    }
};
