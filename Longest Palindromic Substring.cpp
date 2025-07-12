class Solution {
    pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        int n = s.length();
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        return {left + 1, right - left - 1};  // start index and length
    }

public:
    string longestPalindrome(string s) {
        // can do using dp
        int start = 0, maxLen = 1;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            // Odd-length palindrome
            const auto& [startO , lenO] = expandAroundCenter(s, i, i);
            if (lenO > maxLen) {
                start = startO;
                maxLen = lenO;
            }

            // Even-length palindrome
            const auto& [startE, lenE] = expandAroundCenter(s, i, i + 1);
            if (lenE > maxLen) {
                start = startE;
                maxLen = lenE;
            }
        }
        return s.substr(start, maxLen);
    }
};
