class Solution {
    void generate(int left,int right,int& n,string str,vector<string>& ans){
        if(right==n){
            ans.push_back(str);
            return ;
        }
        if(left<n){
            str.push_back('(');
            generate(left+1,right,n,str,ans);
            str.pop_back();
        }
        if(right<left){
            str.push_back(')');
            generate(left,right+1,n,str,ans);
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        // vector<string> ans;
        // string str;
        // generate(0,0,n,str,ans);
        // return ans;
        vector<vector<string>> res(n + 1);
        res[0] = {""};

        for (int k = 0; k <= n; ++k) {
            for (int i = 0; i < k; ++i) {
                for (const string& left : res[i]) {
                    for (const string& right : res[k - i - 1]) {
                        res[k].push_back("(" + left + ")" + right);
                    }
                }
            }
        }

        return res[n];
    }
};