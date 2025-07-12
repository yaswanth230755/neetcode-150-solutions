class Solution {
    int expandAroundCenter(const string& s, int left, int right) {
        int n = s.length();
        int count=0;
        while (left >= 0 && right < n && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;  // start index and length
    }

public:
    int countSubstrings(string s) {
        // can also do using dp
        int ans=0,n = s.length();

        for (int i = 0; i < n; ++i) {
            // Odd-length palindrome+// Even-length palindrome       
            ans+=expandAroundCenter(s, i, i)+expandAroundCenter(s, i, i + 1);
        }
        return ans;
    }
};
