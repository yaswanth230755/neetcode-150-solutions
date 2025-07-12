class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int num1;
        for(const auto token : tokens){
            if(token=="+"){
                num1=st.top();
                st.pop();
                st.top()+=num1;
            }
            else if(token=="-"){
                num1=st.top();
                st.pop();
                st.top()-=num1;
            }
            else if(token=="*"){
                num1=st.top();
                st.pop();
                st.top()*=num1;
            }
            else if(token=="/"){
                num1=st.top();
                st.pop();
                st.top()/=num1;
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};