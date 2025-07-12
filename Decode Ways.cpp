class Solution {
public:
    int numDecodings(string s) {

        /*
        int n = s.length();
        if (n == 0 || s[0] == '0') return 0;

        int first = 1; // dp[i - 2]
        int second = 1; // dp[i - 1]

        for (int i = 1; i < n; ++i) {
            int temp = 0;

            // Check if s[i] is a valid single-digit decode
            if (s[i] != '0') {
                temp += second;
            }

            // Check if s[i-1]s[i] form a valid two-digit decode (10 to 26)
            if ((s[i - 1] == '1') || (s[i - 1] == '2' && s[i] <= '6')) {
                temp += first;
            }

            if (temp == 0) return 0; // No valid decoding

            first = second;
            second = temp;
        }

        return second;
        */

        int n=s.length(),first=0,second=0;
        if(s[0]>='1' && s[0]<='9'){
            first++;
        }
        if(n==1){
            return first;
        }
        if(s[0]>='1' && s[0]<='9' && s[1]>='1' && s[2]<='9'){
            second+=first;
        }
        if(s[0]=='1' || (s[0]=='2' && s[1]>='0' && s[1]<'7')){
            second++;
        }
        if(n==2){
            return second;
        }
        int temp,i=2;
        while(i<n){
            temp=0;
            if((s[i]>='1' && s[i]<='9') || (s[i-1]=='1' || (s[i-1]=='2' && s[i]>='0' && s[i]<'7'))){
                if(s[i]>='1' && s[i]<='9'){
                temp=second;
                }
                if(s[i-1]=='1' || (s[i-1]=='2' && s[i]>='0' && s[i]<'7')){
                    temp+=first;
                }
            }
            else{
                return 0;
            }
            first=second;
            second=temp;
            i++;
        }
        return second;
    }
};
