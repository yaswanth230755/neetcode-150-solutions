class Solution {
public:
    int characterReplacement(string s, int k) {
        int arr[26]={0},maxf=0,n=s.length(),left=0,ans=0;
        for(int i=0;i<n;i++){
            maxf=max(maxf,++arr[s[i]-'A']);
            if(i-left+1-maxf>k){
                arr[s[left++]-'A']--;
            }
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};
