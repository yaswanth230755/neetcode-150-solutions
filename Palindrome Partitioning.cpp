// class Solution {
//     vector<vector<int>> dp; // -1: uncomputed, 0: false, 1: true

//     bool ispalindrome(const string& s, int l, int r) {
//         if (dp[l][r] != -1) return dp[l][r];

//         while (l < r) {
//             if (s[l] != s[r]) return dp[l][r] = 0;
//             l++;
//             r--;
//         }
//         return dp[l][r] = 1;
//     }

//     void construct(const string& s, int index, vector<string>& sub, vector<vector<string>>& ans, const int& n) {
//         if (index == n) {
//             ans.push_back(sub);
//             return;
//         }

//         for (int len = 1; index + len <= n; ++len) {
//             int end = index + len - 1;
//             if (ispalindrome(s, index, end)) {
//                 sub.push_back(s.substr(index, len));
//                 construct(s, index + len, sub, ans, n);
//                 sub.pop_back();
//             }
//         }
//     }

// public:
//     vector<vector<string>> partition(string s) {
//         int n = s.length();
//         dp.assign(n, vector<int>(n, -1)); // Initialize DP table
//         vector<vector<string>> ans;
//         vector<string> sub;
//         construct(s, 0, sub, ans, n);
//         return ans;
//     }
// };


// class Solution {
// public:
//     vector<vector<string>> partition(string s) {
//         vector<vector<string>> res;
//         vector<string> part;
//         dfs(0, s, part, res);
//         return res;
//     }

// private:
//     void dfs(int i, const string& s, vector<string>& part, vector<vector<string>>& res) {
//         if (i >= s.length()) {
//             res.push_back(part);
//             return;
//         }
//         for (int j = i; j < s.length(); j++) {
//             if (isPali(s, i, j)) {
//                 part.push_back(s.substr(i, j - i + 1));
//                 dfs(j + 1, s, part, res);
//                 part.pop_back();
//             }
//         }
//     }

//     bool isPali(const string& s, int l, int r) {
//         while (l < r) {
//             if (s[l] != s[r]) {
//                 return false;
//             }
//             l++;
//             r--;
//         }
//         return true;
//     }
// };


class Solution {
    bool ispalindrome(const string& s){
        int i=0,j=s.length()-1;
        while(i<j && s[i]==s[j]){
            i++;
            j--;
        }
        return i>=j;
    }

    void construct(const string& s,int index,int len,vector<string>& sub,vector<vector<string>>& ans,const int& n){
        string current = s.substr(index, len);
        if(index+len==n){
            if(ispalindrome(current)){
                sub.push_back(current);
                ans.push_back(sub);
                sub.pop_back();
            }
            return ;
        }
        if(ispalindrome(current)){
            sub.push_back(current);
            construct(s,index+len,1,sub,ans,n);
            sub.pop_back();   
        }
        construct(s,index,len+1,sub,ans,n);
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> sub;
        int n=s.length();
        construct(s,0,1,sub,ans,n);
        return ans;
    }
};