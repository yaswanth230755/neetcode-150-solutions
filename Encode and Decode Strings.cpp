class Solution {
public:
    string encode(vector<string>& strs) {
        string ans;
        for (const auto& str : strs) {
            ans += to_string(str.length()) + "#" + str;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while (i < s.length()) {
            int j = i;
            while (isdigit(s[j])) j++;
            int len = stoi(s.substr(i, j - i));
            j++; // skip the '#'
            ans.push_back(s.substr(j, len));
            i = j + len;
        }
        return ans;
    }
};
