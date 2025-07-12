class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        //unordered_set<char> unset({'(','{','['});
        unordered_map<char,char> unmap({{')','('},{'}','{'},{']','['}});
        for(const char& var : s ){
            if(unmap.find(var)==unmap.end()){
                st.push(var);
            }
            else{
                if(!st.empty() && unmap[var]==st.top()){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();


        // stack<char> st;
        // unordered_map<char,char> unmap;
        // unmap[')']='(';
        // unmap['}']='{';
        // unmap[']']='[';
        // for(const auto& ch : s ){
        //     if(ch=='(' || ch=='{' || ch=='['){
        //         st.push(ch);
        //     }
        //     else if(st.empty() || unmap[ch]!=st.top()){
        //         return false;
        //     }
        //     else{
        //         st.pop();
        //     }
        // }
        // return st.empty();
    }
};