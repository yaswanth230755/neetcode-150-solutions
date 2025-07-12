class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.length()-1;
        while(i<j){
            while(i<j && !isalnum(s[i])){
                i++;
            }
            while(i<j && !isalnum(s[j])){
                j--;
            }
            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;


        // int i,j=0,n=s.length();
        // for(i=0;i<n;i++){
        //     if(isalnum(s[i])){
        //         s[j]=tolower(s[i]);
        //         j++;
        //     }
        // }
        // j--;
        // i=0;
        // while(i<j){
        //     if(s[i]!=s[j]){
        //         return false;
        //     }
        //     i++;
        //     j--;
        // }
        // return true;
    }
};