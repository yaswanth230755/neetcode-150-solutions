class Solution {
    vector<string> nums={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void construct(const string& digits,int index,string str,vector<string>& ans){
        if(index==digits.length()){
            ans.push_back(str);
            return ;
        }
        for(const auto& ch : nums[digits[index]-'2']){
            // str + ch creates a new string every time
            str.push_back(ch);
            construct(digits,index+1,str,ans);
            str.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        // can alos do without global variable

        // if (digits.empty()) return {};
        // vector<string> res = {""};
        // vector<string> digitToChar = {
        //     "", "", "abc", "def", "ghi", "jkl",
        //     "mno", "qprs", "tuv", "wxyz"
        // };
        // for (char digit : digits) {
        //     vector<string> tmp;
        //     for (string &curStr : res) {
        //         for (char c : digitToChar[digit - '0']) {
        //             tmp.push_back(curStr + c);
        //         }
        //     }
        //     res = tmp;
        // }
        // return res;


        if(digits.empty()){
            return vector<string>();
        }
        string str;
        vector<string> ans;
        construct(digits,0,str,ans);
        return ans;
    }
};