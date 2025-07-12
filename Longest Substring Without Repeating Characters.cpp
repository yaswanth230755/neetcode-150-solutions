class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // can also use array of 256
        int lastIndex[256] = {-1}; // default: -1 for all
        fill(begin(lastIndex), end(lastIndex), -1);
        
        int start = 0, maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (lastIndex[s[i]] >= start)
                start = lastIndex[s[i]] + 1;
            lastIndex[s[i]] = i;
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;


        // unordered_map<char,int> unmap;
        // int n=s.length(),start=0,max=0;
        // for(int i=0;i<n;i++){
        //     if(unmap.find(s[i])!=unmap.end() && unmap[s[i]]>=start){
        //         start=unmap[s[i]]+1;
        //     }
        //     unmap[s[i]]=i;
        //     max=std::max(max,i-start+1);
        // }
        // return max;
    }
};