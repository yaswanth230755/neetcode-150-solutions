class Solution {
public:
    bool isAnagram(string s, string t) {
        // if we are allowed to change the input
        //can use array as hashmap

        if(s.length()!=t.length())
            return false;
        int arr1[26]={0},n=s.length();
        for(int i=0;i<n;i++){
            arr1[s[i]-'a']++;
            arr1[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(arr1[i]){
                return false;
            }
        }
        return true;


        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // return s==t;
    }
};